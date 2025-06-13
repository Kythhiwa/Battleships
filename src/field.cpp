//
// Created by Kythhiwa on 07.11.2024.
//
#include "field.h"
GameField::GameField(int height, int width) :height_(height), width_(width) {
    if (height <= 0 || width <= 0) {
        throw std::invalid_argument("Invalid field size");
    }
    field_.resize(height, std::vector<CellState> (width, CellState::Empty));
}

GameField::GameField() {
    height_ = 0;
    width_ = 0;
}

GameField::GameField(const GameField& other) : height_(other.height_), width_(other.width_) {
    field_ = other.field_;
    shipPositions_ = other.shipPositions_;
}


GameField& GameField::operator=(const GameField& other) {
    if (this != &other) {
        height_ = other.height_;
        width_ = other.width_;
        field_ = other.field_;
        shipPositions_ = other.shipPositions_;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const GameField& field) {
    os << field.height_ << " " << field.width_ << "\n";
    for (int x = 0; x < field.height_; ++x) {
        for (int y = 0; y <  field.width_; ++y) {
            if (field.shipPositions_.find(std::make_pair(x, y)) != field.shipPositions_.end()) {
                os << field.ch(field.shipPositions_.at(std::make_pair(x, y)).first->getSegmentState(field.shipPositions_.at(std::make_pair(x, y)).second)) << " ";
            }else {
                os << "-1 ";
            }
        }
        os << "\n";
    }
    return os;
}


void GameField::placeShip(Ship& ship, int x, int y, Orientation orientation) {
    ship.setOrientation(orientation);
    int length = ship.getLength();
    int dx = (orientation == Orientation::Horizontal) ? 0 : 1;
    int dy = (orientation == Orientation::Vertical) ? 0 : 1;

    // Проверка на выход за границы поля
    if (x + dx * (length - 1) >= height_ || y + dy * (length - 1) >= width_) {
        throw OutOfBoundsException();
    }

    for (int i = 0; i < length; ++i) {
        int cx = x + dx * i, cy = y + dy * i;
        if (field_[cx][cy] != CellState::Empty) {
            throw ShipPlacementException();
        }
        for (int ox = -1; ox <= 1; ++ox) {
            for (int oy = -1; oy <= 1; ++oy) {
                int nx = cx + ox, ny = cy + oy;
                if (nx == cx || ny == cy) continue;
                if (nx >= 0 && nx < height_ && ny >= 0 && ny < width_ && (ox != 0 || oy != 0) && field_[nx][ny] != CellState::Empty) {
                    int as = 12;
                    throw ShipPlacementException();
                }
            }
        }

        field_[cx][cy] = CellState::Ship;
        shipPositions_[std::make_pair(cx, cy)] = std::make_pair(&ship, i);
    }
}



void GameField::attack(int x, int y, bool DoubleDamage) {
    if (this->isValidPosition(x, y)) {
        if (shipPositions_.find(std::make_pair(x, y)) != shipPositions_.end()) {
            shipPositions_.at(std::make_pair(x, y)).first->hitSegment(shipPositions_.at(std::make_pair(x, y)).second, DoubleDamage);
            if (shipPositions_.at(std::make_pair(x, y)).first->getSegmentState(shipPositions_.at(std::make_pair(x, y)).second) == SegmentState::Destroyed) {
                field_[x][y] = CellState::Empty;
            }
        } else  {
            std::cout << "The cage is empty\n";
        }
    } else {
        throw OutOfBoundsException();
    }
}

void GameField::attackSegment(int i) {
    auto it =shipPositions_.begin();
    std::advance(it, i);
    it->second.first->hitSegment(it->second.second);
}

bool GameField::isDestroyedShip(int x, int y) const {
    if (this->isValidPosition(x, y)) {
        if (shipPositions_.find(std::make_pair(x, y)) != shipPositions_.end()) {
            return shipPositions_.at(std::make_pair(x, y)).first->isDestroyed();
        } else  {
            std::cout << "The cage is empty\n";
        }
    } else {
        throw OutOfBoundsException();
    }
}


bool GameField::isShipHere(int x, int y) const {
    if (isValidPosition(x, y)) {
        if (shipPositions_.find(std::make_pair(x, y)) != shipPositions_.end()) {
            return true;
        }
    }
    return false;
}

int GameField::getHeight() const {
    return height_;
}

int GameField::getWidth() const {
    return width_;
}

int GameField::getCntSegment() const {
    return shipPositions_.size();
}

char GameField::ch(SegmentState o) const{
    if (o == SegmentState::Intact) {
        return '2';
    } else if (o == SegmentState::Damaged) {
        return '1';
    } else return '0';
}


std::map<std::pair<int,int>, std::pair<Ship*, int>>& GameField::getShipPositions() {
    return shipPositions_;
}


bool GameField::isValidPosition(int x, int y) const {
    if (x >= 0 && y >= 0 && x <= width_ && y <= height_) {
        return true;
    } else {
        return false;
    }
}