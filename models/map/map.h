
#ifndef MAP_H
#define MAP_H
#include "../fleet/fleet.h"
#include "../../constants/BalanceSheet.cpp"
class Fleet;
class Map
{
public:
    Map();
    Map(Fleet fleetA, Fleet fleetB);
    void renderFleet(Fleet fleet);
    void print();

private:
    void renderShip(Ship *ship);
    void resetFrame();
    char frameBuffer[BS::MAP_HEIGHT][BS::MAP_WIDTH];
};
#endif