//
// Created by Kythhiwa on 10.11.2024.
//

#ifndef OOP_DOUBLEDAMAGE_H
#define OOP_DOUBLEDAMAGE_H

#include "ability.h"


class DoubleDamage : public Ability {
public:
    void use(GameField &field, int x, int y, bool &status) override;
    Ability* clone() const override;
};


#endif //OOP_DOUBLEDAMAGE_H
