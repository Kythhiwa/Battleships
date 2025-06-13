//
// Created by Kythhiwa on 11.12.2024.
//

#ifndef OOP_INPUTHANDLER_H
#define OOP_INPUTHANDLER_H
#include <bits/stdc++.h>
#include "FileRaII.h"
#include <string>


enum class commands {
    attack,
    useAbility,
    save,
    load,
    quit
};



class InputHandler {
public:
    InputHandler();
    int getInput();
    int getInputArg();
    commands convert(std::string com);
private:
    std::vector<int> cnt = {0,0,0,0,0};
    void loadKeyBindings(const std::string& filename);
    void defaultKeyBindings();
    std::unordered_map<char, commands> keyBindings;
    std::unordered_map<commands, char> commandBindings;
};


#endif //OOP_INPUTHANDLER_H
