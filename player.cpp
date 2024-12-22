//
// Created by Kythhiwa on 29.11.2024.
//

#include "player.h"

Player::Player() : field(1, 1), shipManager(0, {}), enemy(nullptr), lose(false) {
    // Пустой конструктор
}

Player::Player(int height, int width,  std::vector<int> shipLengths) : field(height, width), shipManager(shipLengths.size(), shipLengths), enemy(nullptr){
     initializeField();
}

void Player::attack(int x, int y, bool DoubleDamage) {
    enemy->attack(x, y, DoubleDamage);
    checkStatus();
}

void Player::useAbility(int x, int y, bool &status) {
    Abilities.useAbility(*enemy, x, y, status);
    checkStatus();
}

void Player::checkStatus(){
    if (shipManager.checkShipDestroed()) {
        Abilities.addRandomAbility();
    }
    if (shipManager.allShipsDestroyed()) {
        lose = true;
    }
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    std::vector<Ship*> ships = player.shipManager.getShips();
    os << player.field.getHeight() << " " << player.field.getWidth() << "\n";
    os << ships.size() << "\n";
    for (int i = 0; i < player.a.size(); i++) {
        for (int j = 0; j < 4; j++) {
            os << player.a[i][j] << " ";
        }
        os << "\n";
    }
    for (int i = 0; i < player.a.size(); i++){
        for (int j = 0; j < player.a[i][0]; j++) {
            os << ships[i]->getSegmentStateInt(j) << " ";
        }
        os << "\n";
    }
    os << player.Abilities.getCntAbility() << "\n";
    std::vector<int> types = player.Abilities.getAbilityTypes();
    for (int i = 0; i < types.size(); i++) {
        os << types[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Player& player) {
    int height, width;
    is >> height >> width;
    player.field = GameField(height, width);
    int n;
    is >> n;
    player.a.resize(n, std::vector<int>(4, 0));
    std::vector<int> lens(n);
    for (int i = 0; i < n; i++) {
        is >> player.a[i][0];
        is >> player.a[i][1];
        is >> player.a[i][2];
        is >> player.a[i][3];
        lens[i] = player.a[i][0];
    }
    player.shipManager = ShipManager(n, lens);
    std::vector<Ship*> ships = player.shipManager.getShips();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < player.a[i][0]; j++) {
            int state;
            is >> state;
            ships[i]->setSegmentState(j, state);
        }
        Orientation orientation = Orientation::Horizontal;
        if (player.a[i][3] == 1) {
            orientation = Orientation::Vertical;
        }
        player.field.placeShip(*ships[i], player.a[i][1],  player.a[i][2], orientation);
    }
    // добавить загрузку abilities;
    int cntAbilities;
    is >> cntAbilities;
    player.Abilities = AbilityManager(true);
    for (int i = 0; i < cntAbilities; i++) {
        int k;
        is >> k;
        switch (k) {
            case 0:
                player.Abilities.addDoubleDamage();
                break;
            case 1:
                player.Abilities.addScanner();
                break;
            case 2:
                player.Abilities.addBombing();
                break;
            default:
                // Обработка ошибки, если k не соответствует ни одному из ожидаемых значений
                throw std::runtime_error("Invalid ability type");
        }
    }
    return is;
}




void Player::setEnemy(GameField* enemy) {
    this->enemy = enemy;
}

GameField& Player::getField() {
    return field;
}

bool Player::isLose() {
    return lose;
}

void Player::initializeField() {
    std::vector<Ship*> ships = shipManager.getShips();
    a.resize(ships.size(), std::vector<int>(4, 0));
    for (int i = 0; i < ships.size(); i++) {
        a[i][0] = ships[i]->getLength();
    }
    field.placeShip(*ships[0], 0, 0, Orientation::Horizontal);
    a[0][1] = 0;
    a[0][2] = 0;
    a[0][3] = 0;
    field.placeShip(*ships[1], 1, 4, Orientation::Horizontal);
    a[1][1] = 1;
    a[1][2] = 4;
    a[1][3] = 0;
    field.placeShip(*ships[2], 3, 3, Orientation::Vertical);
    a[2][1] = 3;
    a[2][2] = 3;
    a[2][3] = 1;
    field.placeShip(*ships[3], 3, 5, Orientation::Horizontal);
    a[3][1] = 3;
    a[3][2] = 5;
    a[3][3] = 0;
    field.placeShip(*ships[4], 6, 6, Orientation::Horizontal);
    a[4][1] = 6;
    a[4][2] = 6;
    a[4][3] = 0;
    field.placeShip(*ships[5], 6, 8, Orientation::Horizontal);
    a[5][1] = 6;
    a[5][2] = 8;
    a[5][3] = 0;
    field.placeShip(*ships[6], 9, 2, Orientation::Horizontal);
    a[6][1] = 9;
    a[6][2] = 2;
    a[6][3] = 0;
    field.placeShip(*ships[7], 4, 0, Orientation::Vertical);
    a[7][1] = 4;
    a[7][2] = 0;
    a[7][3] = 1;
}


int Player::getTypeAbility() {
    std::vector<int> t = Abilities.getAbilityTypes();
    return t.at(0);
}
