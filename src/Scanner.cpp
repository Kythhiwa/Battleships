//
// Created by kythhiwa on 14.11.2024.
//

#include "Scanner.h"

void Scanner::use(GameField &field, int x, int y, bool &status){
    bool flag = false;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (field.isShipHere(x + i, y + j)) {
                flag = true;
            }
        }
    }
    status = flag;
}

Ability* Scanner::clone() const {
    return new Scanner(*this);
}