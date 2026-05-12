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
    void addShip(Ship *);
    void addShip(int);
    void align(int);
    void choose();
    Ship *getShip(int );
    vector<Ship *> getShips();

private:
    vector<Ship *> ships;
};
#endif