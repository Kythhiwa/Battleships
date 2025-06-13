//
// Created by Kythhiwa on 30.11.2024.
//

#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H
#include "game.h"
#include "FileRaII.h"

class GameState {
public:
    GameState(Game& game);

    friend std::ostream& operator<<(std::ostream& os, const GameState& state);
    friend std::istream& operator>>(std::istream& is, GameState& state);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    Game game;
};

#endif //OOP_GAMESTATE_H
