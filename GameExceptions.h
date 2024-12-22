//
// Created by Kythhiwa on 18.11.2024.
//

#ifndef OOP_GAMEEXCEPTIONS_H
#define OOP_GAMEEXCEPTIONS_H
#include "GameException.h"


class NoAbilityException : public GameException {
public:
    NoAbilityException() : GameException("No abilities available") {}
};

class ShipPlacementException : public GameException {
public:
    ShipPlacementException() : GameException("Invalid ship placement") {}
};

class OutOfBoundsException : public GameException {
public:
    OutOfBoundsException() : GameException("Attack out of bounds") {}
};

#endif //OOP_GAMEEXCEPTIONS_H
