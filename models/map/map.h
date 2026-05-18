#pragma once
#ifndef MAP_H
#define MAP_H
#include <string.h>
#include <vector>
#include "../projectile/projectile.h"
#include "../fleet/fleet.h"
#include "../../constants/BalanceSheet.cpp"

class Projectile;
class Ship;
class Fleet;
class Map
{
public:
    Map();
    void renderFleet(Fleet fleet);
    void printFrame();

private:
    void renderShip(Ship *ship, bool isActive);
    void resetFrame();
    std::string frameBuffer[BS::MAP_HEIGHT][BS::MAP_WIDTH];
    Fleet *fleetA;
    Fleet *fleetB;
    std::vector<Projectile> projectiles;
};
#endif