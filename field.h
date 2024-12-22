//
// Created by Kythhiwa on 07.11.2024.
//

#ifndef OOP_FIELD_H
#define OOP_FIELD_H
#include <bits/stdc++.h>
#include "ship.h"
#include "manager.h"
#include "GameExceptions.h"

enum class CellState {
    Empty,
    Ship
};

class GameField {
public:
    GameField(int height, int width);
    GameField();
    GameField(const GameField& other);

    GameField& operator=(const GameField& other);
    friend std::ostream& operator<<(std::ostream& os, const GameField& field);

    void placeShip(Ship& ship, int x, int y, Orientation orientation);
    void attack(int x, int y, bool DoubleDamage=false);
    void attackSegment(int c);
    bool isValidPosition(int x, int y) const;
    bool isShipHere(int x, int y) const;
    bool isDestroyedShip(int x, int y) const;
    int getHeight() const;
    int getWidth() const;
    int getCntSegment() const;
    char ch(SegmentState o) const;
    std::map<std::pair<int,int>, std::pair<Ship*, int>>& getShipPositions(); 

private:
    
    int height_, width_;
    std::vector<std::vector<CellState>> field_;
    std::map<std::pair<int,int>, std::pair<Ship*, int>> shipPositions_;
};
/*создадим вектор или мапу котоаря хранит координаты куда поставили корабль и его ориентацию потом в файл записываем {x y orientation и цифры segmentstate например 2 1 2}
 * возможно потребуется расстаялть*/

#endif //OOP_FIELD_H
