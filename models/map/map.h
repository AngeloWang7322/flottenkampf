#pragma once
#ifndef MAP_H
#define MAP_H
#include <string.h>
#include <vector>
#include <array>
#include "../projectile/projectile.h"
#include "../fleet/fleet.h"
#include "../../constants/BalanceSheet.cpp"

using namespace std;

class Projectile;
class Ship;
class Fleet;
class Map
{
public:
    Map();
    void renderFleet(Fleet fleet);
    void printFrame();
    bool areaIsEmpty(int fromX, int toX, int fromY, int toY, Ship *ignore = nullptr);
    void setFleets(Fleet *fleetA, Fleet *fleetB);
    static bool isOutOfMap(int x, int y);

private:
    void renderShip(Ship *ship, bool isActive);
    void resetFrame();
    void renderProjectiles();
    vector<Ship *> getAllShips();
    array<array<Ship *, BS::MAP_WIDTH>, BS::MAP_HEIGHT> getShipMap();
    string frameBuffer[BS::MAP_HEIGHT][BS::MAP_WIDTH]{};
    Fleet *fleetA;
    Fleet *fleetB;
};
#endif