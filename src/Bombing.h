//
// Created by Kythhiwa on 14.11.2024.
//

#ifndef OOP_BOMBING_H
#define OOP_BOMBING_H
#include "ability.h"


class Bombing : public Ability {
public:
    void use(GameField &field, int x, int y, bool &status) override;
    Ability* clone() const override;
};

#endif //OOP_BOMBING_H
