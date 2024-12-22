//
// Created by Kythhiwa on 07.11.2024.
//

#include "ship.h"

Ship::Ship(int length): length_(length){
    if (length < 1 || length > 4) {
        throw std::invalid_argument("Invalid ship length\n");
    }
    segments_.resize(length, SegmentState::Intact);
}


void Ship::hitSegment(int indexSegment, bool DoubleDamage) {
    if (indexSegment < 0 || indexSegment > length_) {
        throw std::out_of_range("Invalid segment index\n");
    }
    if (segments_[indexSegment] == SegmentState::Destroyed) {
        std::cout << "~The segment of the ship has already been destroyed\n";
    } else {
        std::cout << "~Hit segment\n";
    }
    if (!DoubleDamage) {
        if (segments_[indexSegment] == SegmentState::Intact) {
            segments_[indexSegment] = SegmentState::Damaged;
        } else if (segments_[indexSegment] == SegmentState::Damaged) {
            segments_[indexSegment] = SegmentState::Destroyed;
        }
    } else {
        segments_[indexSegment] = SegmentState::Destroyed;
    }

}

void Ship::setOrientation(Orientation orientation) {
    orientation_ = orientation;
}

bool Ship::isDestroyed() const{
    for (const auto now : segments_) {
        if (now != SegmentState::Destroyed) {
            return false;
        }
    }
    return true;
}



int Ship::getLength() const{
    return length_;
}

Orientation Ship::getOrientation() const{    return orientation_;
}

SegmentState Ship::getSegmentState(int indexSegment) const{
    if (indexSegment < 0 || indexSegment > length_) {
        throw std::out_of_range("Invalid segment index");
    }
    return segments_[indexSegment];
}
int Ship::getSegmentStateInt(int indexSegment) const {
    if (indexSegment < 0 || indexSegment > length_) {
        throw std::out_of_range("Invalid segment index");
    }
    if (segments_[indexSegment] == SegmentState::Intact) {
        return 2;
    } else if (segments_[indexSegment] == SegmentState::Damaged) {
        return 1;
    } else return 0;
}


void Ship::setSegmentState(int indexSegment, int state) {
    if (indexSegment < 0 || indexSegment > length_) {
        throw std::out_of_range("Invalid segment index");
    }
    if (state == 1) {
        segments_[indexSegment] = SegmentState::Damaged;
    } else if (state == 0) {
        segments_[indexSegment] = SegmentState::Destroyed;
    } else if (state == 2) {
        segments_[indexSegment] = SegmentState::Intact;
    }
}