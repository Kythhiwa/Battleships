cmake_minimum_required(VERSION 3.22)
project(OOPTRUE)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOPTRUE main.cpp AbilityManager.cpp AbilityManager.h ability.h Bombing.cpp Bombing.h DoubleDamage.h DoubleDamage.cpp enemy.cpp enemy.h field.h field.cpp FileRaII.cpp FileRaII.h game.cpp game.h GameController.h GameException.h GameExceptions.h GameState.cpp GameState.h InputHandler.h InputHandler.cpp manager.cpp manager.h  player.cpp player.h Render.cpp Render.h Scanner.cpp Scanner.h ship.cpp ship.h)
