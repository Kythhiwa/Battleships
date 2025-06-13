//
// Created by Kythhiwa on 18.11.2024.
//

#ifndef OOP_GAMEEXCEPTION_H
#define OOP_GAMEEXCEPTION_H
#include <exception>
#include <string>

class GameException : public std::exception {
public:
    GameException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }

protected:
    std::string message;
};

#endif //OOP_GAMEEXCEPTION_H
