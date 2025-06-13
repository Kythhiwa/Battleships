//
// Created by Kythhiwa on 30.11.2024.
//

#include "GameState.h"
GameState::GameState(Game& game)
        : game(game) {}

std::ostream& operator<<(std::ostream& os, const GameState& state) {
    // Serialize game state to stream
    os << state.game.getPlayer() << "\n";
    os << state.game.getEnemy() << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, GameState& state) {
    // Deserialize game state from stream
    try {
        is >> state.game.getPlayer();
        is >> state.game.getEnemy();
    }catch(const std::exception& e) {
        throw std::runtime_error("Error in the save file\n");
    }
    return is;
}

void GameState::saveToFile(const std::string& filename) const {
    std::cout << "Saving game state to file: " << filename << std::endl;
    FileRAII file(filename, std::ios::out | std::ios::binary);
    if (file.isOpen()) {
        std::cout << "File opened successfully." << std::endl;
        std::fstream &ofs = file.getStream();
        ofs << *this;
        std::cout << "Game state saved successfully." << std::endl;
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

void GameState::loadFromFile(const std::string& filename) {
    FileRAII file(filename, std::ios::in | std::ios::binary);
    if (file.isOpen()) {
        std::fstream& ifs = file.getStream();
        ifs >> *this;
    }
}
