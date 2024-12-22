//
// Created by Kythhiwa on 29.11.2024.
//

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H
#include "AbilityManager.h"
#include "manager.h"
#include "field.h"
#include "ship.h"

class Enemy {
public:
    Enemy();
    Enemy(int height, int width, std::vector<int> shipLengths);
    Enemy& operator=(const Enemy& other);

    void attack();
    bool isLose();

    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);
    friend std::istream& operator>>(std::istream& is, Enemy& enemy);
    void setPlayer(GameField* player);
    GameField& getField();
private:
    GameField field;
    ShipManager shipManager;
    GameField* player;
    std::vector<std::vector<int>> a; // len x y orientation segmentstate
    void initializeField();
    void checkStatus();
    bool lose=false;
};

#endif //OOP_ENEMY_H
