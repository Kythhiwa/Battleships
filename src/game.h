//
// Created by Kythhiwa on 30.11.2024.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "player.h"
#include "enemy.h"
#include <vector>


class GameState;

class Game {
public:
    Game();
    bool End();
    void generateEnemy();
    void enemyTurn();
    void attack(int x, int y);
    void useAbility(int x, int y, bool &status);
    void save();
    void load();
    void setPlayer(int height, int width, std::vector<int> lens);
    Player& getPlayer() const;
    Enemy& getEnemy() const;
    void endGame();

private:
    Player* player;
    Enemy* enemy;
    bool end;
    GameState* gameState;
};

#endif //OOP_GAME_H