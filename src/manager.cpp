//
// Created by Kythhiwa on 07.11.2024.
//

#include "manager.h"

ShipManager::ShipManager(int count, std::vector<int> len) : count_(count), countDestroyed_(0){
    for (const auto& now: len) {
        Ship* shipPtr = new Ship(now);
        ships_.push_back(shipPtr);
    }
}

ShipManager &ShipManager::operator=(const ShipManager &other) {
    if (this == &other) {
        return *this;
    }
    for (auto shipPtr : ships_) {
        delete shipPtr;
    }
    ships_.clear();
    count_ = other.count_;
    countDestroyed_ = other.countDestroyed_;
    for (const auto& shipPtr : other.ships_) {
        ships_.push_back(new Ship(*shipPtr));
    }

    return *this;
}

bool ShipManager::allShipsDestroyed() {
    for (const auto now : ships_) {
        if (!now->isDestroyed()) return false;
    }
    return true;
}

bool ShipManager::checkShipDestroed() {
    int cnt = 0;
    for (const auto now : ships_) {
        if (now->isDestroyed()) cnt++;
    }
    if (cnt != countDestroyed_) {
        countDestroyed_ = cnt;
        return true;
    }
    return false;

}

int ShipManager::getShipCount() const{
    return count_;
}

int ShipManager::getShipAlive() const{
    return count_ - countDestroyed_;
}

int ShipManager::getShipDestoyed() {
    return countDestroyed_;
}

std::vector<Ship*> ShipManager::getShips() const{
    return ships_;
}

ShipManager::~ShipManager() {
    for (auto shipPtr : ships_) {
        delete shipPtr;
    }
}