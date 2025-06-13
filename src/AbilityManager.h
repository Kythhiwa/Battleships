//
// Created by Kythhiwa on 10.11.2024.
//

#ifndef OOP_ABILITYMANAGER_H
#define OOP_ABILITYMANAGER_H
#include <bits/stdc++.h>
#include "ability.h"
#include "GameExceptions.h"
#include "DoubleDamage.h"
#include "Scanner.h"
#include "Bombing.h"

class AbilityManager {
public:
    AbilityManager(bool noAbility=false);
    void useAbility(GameField &field, int x, int y, bool &status);
    void addRandomAbility();
    void addDoubleDamage();
    void addScanner();
    void addBombing();
    std::vector<int> getAbilityTypes() const;

    AbilityManager& operator=(const AbilityManager& other);

    int getCntAbility() const;
    ~AbilityManager();
private:
    std::queue<Ability*> abilities;
};

#endif //OOP_ABILITYMANAGER_H
