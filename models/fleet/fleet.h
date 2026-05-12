#ifndef FLEET_H
#define FLEET_H
#include <vector>
#include <stdio.h>
#include <memory>
#include "../ship/ship.h"

using namespace std;
class Fleet
{
public:
    Fleet();
    void addShip(Ship *ship);
    Ship *getShip(int index);
    vector<Ship *> getShips();

private:
    vector<Ship *> ships;
};
#endif