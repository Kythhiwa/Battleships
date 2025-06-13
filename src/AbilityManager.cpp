//
// Created by kythhiwa on 10.11.2024.
//

#include "AbilityManager.h"

AbilityManager::AbilityManager(bool noAbility) {
    if (!noAbility) {
        srand(static_cast<unsigned int>(time(0)));
        std::vector<Ability*> ability;
        ability.push_back(new DoubleDamage());
        ability.push_back(new Scanner());
        ability.push_back(new Bombing());
        std::random_shuffle(ability.begin(), ability.end());
        for (auto &abil: ability) {
            abilities.push(abil);
        }
    }
}

void AbilityManager::addDoubleDamage() {
    abilities.push(new DoubleDamage());
}

void AbilityManager::addBombing() {
    abilities.push(new Bombing());
}

void AbilityManager::addScanner() {
    abilities.push(new Scanner());
}

std::vector<int> AbilityManager::getAbilityTypes() const {
    std::vector<int> types;
    std::queue<Ability*> tempQueue = abilities;
    while (!tempQueue.empty()) {
        Ability* ability = tempQueue.front();
        if (dynamic_cast<DoubleDamage*>(ability)) {
            types.push_back(0);
        } else if (dynamic_cast<Scanner*>(ability)) {
            types.push_back(1);
        } else if (dynamic_cast<Bombing*>(ability)) {
            types.push_back(2);
        }
        tempQueue.pop();
    }
    return types;
}

AbilityManager &AbilityManager::operator=(const AbilityManager& other) {
    if (this == &other) {
        return *this;
    }
    while (!abilities.empty()) {
        delete abilities.front();
        abilities.pop();
    }

    std::queue<Ability*> tempQueue;
    std::queue<Ability*> otherQueue = other.abilities;
    while (!otherQueue.empty()) {
        tempQueue.push(otherQueue.front()->clone());
        otherQueue.pop();
    }

    abilities = tempQueue;

    return *this;
}

void AbilityManager::useAbility(GameField &field, int x, int y, bool &status) {
    if (abilities.empty()) {
        throw NoAbilityException();
    }
    Ability* ability = abilities.front();
    abilities.pop();
    ability->use(field, x, y, status);
    delete ability;
}

void AbilityManager::addRandomAbility() {
    int choice = rand() % 3;
    switch (choice) {
        case 0:
            abilities.push(new DoubleDamage());
            break;
        case 1:
            abilities.push(new Scanner());
            break;
        case 2:
            abilities.push(new Bombing());
            break;
    }
}

int AbilityManager::getCntAbility() const {
    return abilities.size();
}

AbilityManager::~AbilityManager() {
    while (!abilities.empty()) {
        delete abilities.front();
        abilities.pop();
    }
}