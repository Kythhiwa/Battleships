//
// Created by Kythhiwa on 14.11.2024.
//

#include "Bombing.h"


void Bombing::use(GameField &field, int x, int y, bool &status){
    int c = rand() % field.getCntSegment();
    field.attackSegment(c);
    status = true;
}

Ability* Bombing::clone() const {
    return new Bombing(*this);
}