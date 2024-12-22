//
// Created by Kythhiwa on 07.11.2024.
//

#ifndef OOP_SHIP_H
#define OOP_SHIP_H

#include <bits/stdc++.h>

enum class Orientation {
    Horizontal,
    Vertical
};

enum class SegmentState{
    Intact,
    Damaged,
    Destroyed
};

class Ship {
public:
    Ship(int length);

    void hitSegment(int indexSegment, bool DoubleDamage=false);
    bool isDestroyed() const;

    //getters
    int getLength() const;
    Orientation getOrientation() const;
    SegmentState getSegmentState(int indexSegment) const;
    int getSegmentStateInt(int indexSegment) const;
    //setters
    void setOrientation(Orientation orientation);
    void setSegmentState(int indexSegment, int state);

private:
    Orientation orientation_ = Orientation::Horizontal;
    std::vector<SegmentState> segments_;
    int length_;
};
#endif //OOP_SHIP_H
