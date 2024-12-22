//
// Created by Kythhiwa on 11.12.2024.
//

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "game.h"

template <typename InputHandler, typename RenderStrategy>
class GameController {
public:
    GameController(Game& game) : game(game) {}
    
    void startGame(int height, int width, std::vector<int> lens) {
        game.setPlayer(height, width, lens);
        InputHandler inputHandler;
        RenderStrategy renderStrategy;
        game.generateEnemy();
        int cur_ability = -1;
        bool status = false;
        while(!game.End()) {
            renderStrategy.render(game, cur_ability, status);
            int key = inputHandler.getInput();
            cur_ability = -1;
            status = false;
            switch (key) {
                case 0: {
                    int x = inputHandler.getInputArg(), y = inputHandler.getInputArg();
                    game.attack(x, y);
                    break;
                }
                case 1: {
                    int x = -1, y = -1;
                    cur_ability = game.getPlayer().getTypeAbility();
                    if (cur_ability != 2) {
                        x = inputHandler.getInputArg(), y = inputHandler.getInputArg();
                    }
                    game.useAbility(x, y, status);
                    break;
                }
                case 2:
                    game.save();
                    break;
                case 3:
                    game.load();
                    break;
                case 4:
                    game.endGame();
                    break;
            }
            game.enemyTurn();
        }
    }


private:
    Game& game;
};

#endif // GAME_CONTROLLER_H