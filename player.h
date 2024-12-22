//
// Created by Kythhiwa on 29.11.2024.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "AbilityManager.h"
#include "manager.h"
#include "field.h"
#include "ship.h"


class Player {
public:

    Player();
    Player(int height, int width, std::vector<int> shipLengths);

    void attack(int x, int y, bool DoubleDamage=false);
    void useAbility(int x, int y, bool &status);
    bool isLose();
    void setEnemy(GameField* enemy);
    int getTypeAbility();
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    friend std::istream& operator>>(std::istream& is, Player& player);


    GameField& getField();
private:
    GameField field;
    ShipManager shipManager;
    AbilityManager Abilities;
    GameField* enemy;
    std::vector<std::vector<int>> a; // len x y orientation segmentstate
    void initializeField();
    void checkStatus();
    bool lose=false;
};


#endif //OOP_PLAYER_H
