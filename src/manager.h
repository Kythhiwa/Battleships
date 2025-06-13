//
// Created by Kythhiwa on 07.11.2024.
//

#ifndef OOP_MANAGER_H
#define OOP_MANAGER_H

#include <bits/stdc++.h>
#include "ship.h"



class ShipManager {
public:
    ShipManager(int count, std::vector<int> len);

    ShipManager& operator=(const ShipManager& other);

    bool allShipsDestroyed();
    bool checkShipDestroed();
    int getShipCount() const;
    int getShipAlive() const;
    int getShipDestoyed();
    std::vector<Ship*> getShips() const;

    ~ShipManager();
private:
    int count_;
    int countDestroyed_;
    std::vector<Ship*> ships_;
};

#endif //OOP_MANAGER_H
