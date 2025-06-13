//
// Created by Kythhiwa on 11.12.2024.
//

#ifndef OOP_RENDER_H
#define OOP_RENDER_H
#include "game.h"


class Render {
public:
    void render(Game &game, int cur_ability, bool status);
private:
    void clearConsole() const;
};


#endif //OOP_RENDER_H
