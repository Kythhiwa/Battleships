#include <bits/stdc++.h>
#include "ship.h"
#include "field.h"
#include "DoubleDamage.h"
#include "AbilityManager.h"
#include "player.h"
#include "enemy.h"
#include "game.h"
#include "GameState.h"
#include "FileRaII.h"
#include "GameController.h"
#include "Render.h"
#include "InputHandler.h"
int main() {
    Game game;
    GameController<InputHandler, Render> controller(game);
    std::vector<int> shipLengths = {3, 2, 2, 4, 1, 1, 1, 3};
    controller.startGame(10, 10, shipLengths);
}
