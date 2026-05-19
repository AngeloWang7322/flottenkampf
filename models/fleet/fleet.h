#pragma once
#ifndef FLEET_H
#define FLEET_H
#include <vector>
#include <stdio.h>
#include <memory>
#include "../map/map.h"
#include "../ship/ship.h"

using namespace std;
class Map;
class Fleet
{
public:
    Fleet() = default;
    Fleet(Map &);
    bool tryMoveShip(Pos move, Ship* ship);
    bool execute(Action action);
    void startAttacking(Fleet*);
    void align(int);
    void addShip(Ship *);
    void addShip(int);
    void setActive(int);
    int getActive();
    Ship *getActiveShip();
    Ship *getShip(int);
    vector<Ship *> getShips();

private:
    void changeActive();
    vector<Ship *> ships;
    Map &map;
    int active;
};
#endif