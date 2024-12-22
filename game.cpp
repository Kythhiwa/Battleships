//
// Created by Kythhiwa on 30.11.2024.
//

#include "game.h"
#include <iostream>
#include <cstdlib> // Для system()

#include "GameState.h" 




Game::Game() {
    player = new Player();
    enemy = new Enemy();
    end = false;
    gameState = new GameState(*this);    
}

void Game::attack(int x, int y) {
    player->attack(x, y);
}

void Game::useAbility(int x, int y, bool &status) {
    player->useAbility(x, y, status);
}

void Game::save() {
    gameState->saveToFile("game_state.dat");
}

void Game::load() {
    gameState->loadFromFile("game_state.dat");
}


void Game::setPlayer(int height, int width, std::vector<int> lens) {
    if (player != nullptr) {
        delete player;
    }
    player = new Player(height, width, lens);
    enemy->setPlayer(&player->getField());
    player->setEnemy(&enemy->getField());
}

void Game::enemyTurn() {
    enemy->attack();
}



bool Game::End() {
    return end;
}

void Game::generateEnemy() {
    if (enemy != nullptr) {
        delete enemy;
    }
    std::vector<int> shipLengths = {3, 2, 2, 4, 1, 1, 1, 3};
    enemy = new Enemy(10, 10, shipLengths);
    enemy->setPlayer(&player->getField());
    player->setEnemy(&enemy->getField());
}

void Game::endGame() {
    end = true;
}

Player& Game::getPlayer() const {
    return *player;
}

Enemy& Game::getEnemy() const {
    return *enemy;
}
