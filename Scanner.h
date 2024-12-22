//
// Created by Kythhiwa on 14.11.2024.
//

#ifndef OOP_SCANNER_H
#define OOP_SCANNER_H
#include "ability.h"


class Scanner : public Ability {
public:
    void use(GameField &field, int x, int y, bool &status) override;
    Ability* clone() const override;
};


#endif //OOP_SCANNER_H
