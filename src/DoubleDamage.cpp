//
// Created by Kythhiwa on 10.11.2024.
//

#include "DoubleDamage.h"


void DoubleDamage::use(GameField &field, int x, int y, bool &status){
    field.attack(x, y, true);
    status = true;
}

Ability* DoubleDamage::clone() const {
    return new DoubleDamage(*this);
}