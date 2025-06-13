//
// Created by maksv on 10.11.2024.
//

#ifndef OOP_ABILITY_H
#define OOP_ABILITY_H
#include <bits/stdc++.h>
#include "field.h"


class Ability{
public:
    virtual void use(GameField &field, int x, int y, bool &status) = 0;
    virtual ~Ability() = default;
    virtual Ability* clone() const = 0;
};


#endif //OOP_ABILITY_H
