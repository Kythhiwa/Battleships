//
// Created by Kythhiwa on 11.12.2024.
//

#include "InputHandler.h"
InputHandler::InputHandler() {
    loadKeyBindings("a.txt");
}

int InputHandler::getInput() {
    char key;
    std::cin >> key;
    return static_cast<int>(keyBindings[key]);
}

int InputHandler::getInputArg() {
    int k; std::cin >> k;
    return k;
}

commands InputHandler::convert(std::string com) {
    if (com == "attack") {
        cnt[0] = 1;
        return commands::attack;
    }else if (com == "save") {
        cnt[2] = 1;
        return commands::save;
    } else if (com == "useAbility") {
        cnt[1] = 1;
        return commands::useAbility;
    } else if (com == "load") {
        cnt[3] = 1;
        return commands::load;
    } else if (com == "quit") {
        cnt[4] = 1;
        return commands::quit;
    }
}
void InputHandler::loadKeyBindings(const std::string& filename) {
    // Используем FileRAII для открытия файла
    FileRAII file(filename,  std::ios::in);

    if (!file.isOpen()) {
        std::cerr << "Failed to open keybindings file. Using default bindings." << std::endl;
        defaultKeyBindings();
        return;
    }

    std::fstream& stream = file.getStream();
    char key;
    std::string command;
    std::map<std::string,int> check;
    while (stream >> key >> command) {

        if (keyBindings.find(key) != keyBindings.end()) {
            std::cerr << "Error: Duplicate key binding for key '" << key << "'." << std::endl;
            continue; 
        }
        if (commandBindings.find(convert(command)) != commandBindings.end()) {
            std::cerr << "Error: Duplicate command binding for command '" << command << "'." << std::endl;
            continue; 
        }
        // Добавляем соответствие в словари
        keyBindings[key] = convert(command);
        commandBindings[convert(command)] = key;
    }
    for (auto now: cnt) {
        if (now == 0) {
           std::cout << "not enough command\n"; 
        }
    }
    // Если файл пустой или не содержит корректных данных, используем настройки по умолчанию
    if (keyBindings.empty()) {
        std::cerr << "Keybindings file is empty or invalid. Using default bindings." << std::endl;
        defaultKeyBindings();
    }
}

void InputHandler::defaultKeyBindings() {
    keyBindings = {
            {'a', commands::attack},       // Атака
            {'u', commands::useAbility},   // Использовать способность
            {'s', commands::save},         // Сохранить игру
            {'l', commands::load},         // Загрузить игру
            {'q', commands::quit}          // Выйти из игры
    };

    // Заполняем обратный словарь для проверки дубликатов
    for (const auto& pair : keyBindings) {
        commandBindings[pair.second] = pair.first;
    }
}