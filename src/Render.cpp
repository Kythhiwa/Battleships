//
// Created by Kythhiwa on 11.12.2024.
//

#include "Render.h"
#include <cstdlib>
#include <iostream>

void Render::clearConsole() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void Render::render(Game &game, int cur_ability, bool status) {
    clearConsole();
    std::cout << "    ";
    for (int j = 0; j < game.getPlayer().getField().getWidth() ; j++) {
        std::cout << j << " ";
    }
    std::cout << "\n";
    std::cout << "  ";
    for (int j = 0; j < game.getPlayer().getField().getWidth(); j++) {
        std::cout << "__";
    }
    std::cout << "\n";

    std::map<std::pair<int,int>, std::pair<Ship*, int>>& shipPosition = game.getPlayer().getField().getShipPositions();

    for (int i = 0; i < game.getPlayer().getField().getHeight(); i++) {
        std::cout << i << " | ";
        for (int j = 0; j < game.getPlayer().getField().getWidth(); j++) {
            if (shipPosition.find(std::make_pair(i, j)) != game.getPlayer().getField().getShipPositions().end()) {
                std::cout << game.getPlayer().getField().ch(shipPosition.at(std::make_pair(i, j)).first->getSegmentState(shipPosition.at(std::make_pair(i, j)).second)) << " ";
            } else {
                std::cout << '#' << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "    ";
    for (int j = 0; j < game.getPlayer().getField().getWidth() ; j++) {
        std::cout << j << " ";
    }
    std::cout << "\n";
    std::cout << "  ";
    for (int j = 0; j < game.getPlayer().getField().getWidth(); j++) {
        std::cout << "__";
    }
    std::cout << "\n";

    std::map<std::pair<int,int>, std::pair<Ship*, int>>& shipPosition1 = game.getEnemy().getField().getShipPositions();

    for (int i = 0; i < game.getEnemy().getField().getHeight(); i++) {
        std::cout << i << " | ";
        for (int j = 0; j < game.getEnemy().getField().getWidth(); j++) {
            if (shipPosition1.find(std::make_pair(i, j)) != game.getEnemy().getField().getShipPositions().end()) {
                std::cout << game.getEnemy().getField().ch(shipPosition1.at(std::make_pair(i, j)).first->getSegmentState(shipPosition1.at(std::make_pair(i, j)).second)) << " ";
            } else {
                std::cout << '#' << " ";
            }
        }
        std::cout << "\n";
    }
    if (cur_ability != -1) {
        switch (cur_ability) {
            case (0):
                std::cout << "DoubleDamage applied!\n";
                break;
            case (1):
                if (status) {
                    if (status) {
                        std::cout << "~There's a ship here\n";
                    } else {
                        std::cout << "~There is no ship here\n";
                    }
                }
                std::cout << "Scanner applied!\n";
                break;
            case (2):
                std::cout << "Bombing applied!\n";
                break;
        }
    }
    std::cout << "attack useAbility save load quit\n";
}