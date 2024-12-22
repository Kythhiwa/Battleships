//
// Created by maksv on 29.11.2024.
//

#include "enemy.h"

Enemy::Enemy() : field(1, 1), shipManager(0, {}), player(nullptr) {
    // Пустой конструктор
}
Enemy::Enemy(int height, int width, std::vector<int> shipLengths) : field(height, width),  shipManager(shipLengths.size(), shipLengths), player(nullptr){
    initializeField();
}

Enemy& Enemy::operator=(const Enemy& other) {
    if (this == &other) {
        return *this;
    }
    field = other.field;
    shipManager = other.shipManager;
    player = other.player;
    a = other.a;
    lose = other.lose;
    return *this;
}


void Enemy::initializeField() {
    std::vector<Ship*> ships = shipManager.getShips();
    int i = 0;
    a.resize(ships.size(), std::vector<int>(4, 0));
    for (auto &now : ships) {
        bool place = false;
        while (!place) {
            int x = rand() % field.getHeight();
            int y = rand() % field.getWidth();
            int h = rand() % 2;
            bool f = field.isShipHere(x, y);
            Orientation orientation = (h == 0 ? Orientation::Horizontal : Orientation::Vertical);
            try {
                field.placeShip(*now, x, y, orientation);
            } catch (const ShipPlacementException &) {}
              catch (const OutOfBoundsException &) {}
            if (field.isShipHere(x, y) && !f) place = true;
            a[i][0] = now->getLength();
            a[i][1] = x;
            a[i][2] = y;
            a[i][3] = h;
        }
        i++;
    }
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    std::vector<Ship*> ships = enemy.shipManager.getShips();
    os << enemy.field.getHeight() << " " << enemy.field.getWidth() << "\n";
    os << ships.size() << "\n";
    for (int i = 0; i < enemy.a.size(); i++) {
        for (int j = 0; j < 4; j++) {
            os << enemy.a[i][j] << " ";
        }
        os << "\n";
    }
    for (int i = 0; i < enemy.a.size(); i++){
        for (int j = 0; j < enemy.a[i][0]; j++) {
            os << ships[i]->getSegmentStateInt(j) << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Enemy& enemy) {
    int height, width;
    is >> height >> width;
    enemy.field = GameField(height, width);
    int n;
    is >> n;
    enemy.a.resize(n, std::vector<int>(4, 0));
    std::vector<int> lens(n);
    for (int i = 0; i < n; i++) {
        is >> enemy.a[i][0];
        is >> enemy.a[i][1];
        is >> enemy.a[i][2];
        is >> enemy.a[i][3];
        lens[i] = enemy.a[i][0];
    }
    enemy.shipManager = ShipManager(n, lens);
    std::vector<Ship*> ships = enemy.shipManager.getShips();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < enemy.a[i][0]; j++) {
            int state;
            is >> state;
            ships[i]->setSegmentState(j, state);
        }
        Orientation orientation = Orientation::Horizontal;
        if (enemy.a[i][3] == 1) {
            orientation = Orientation::Vertical;
        }
        try {
            enemy.field.placeShip(*ships[i], enemy.a[i][1],  enemy.a[i][2], orientation);
        } catch (const ShipPlacementException &) {}
        catch (const OutOfBoundsException &) {}
    }
    return is;
}


void Enemy::attack() {
    int x = rand() % field.getHeight();
    int y = rand() % field.getWidth();
    player->attack(x, y);
}

void Enemy::setPlayer(GameField* player) {
    this->player = player;
}

GameField& Enemy::getField() {
    return field;
}

bool Enemy::isLose() {
    return lose;
}


void Enemy::checkStatus(){
    shipManager.checkShipDestroed();
    if (shipManager.allShipsDestroyed()) {
        lose = true;
    }
}

