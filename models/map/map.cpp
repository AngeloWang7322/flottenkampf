#include <stdio.h>
#include <iostream>
#include "map.h"
#include "../fleet/fleet.h"
#include "../../constants/BalanceSheet.cpp"
Map::Map()
{
    this->resetFrame();
}

void Map::print()
{
    system("clear");
    for (int y = 0; y < BS::MAP_HEIGHT; y++)
    {
        for (int x = 0; x < BS::MAP_WIDTH; x++)
        {
            cout << frameBuffer[y][x];
        }
        cout << "\n";
    }
}

void Map::renderFleet(Fleet fleet)
{
    for (Ship *ship : fleet.getShips())
        renderShip(ship);
}

void Map::resetFrame()
{
    for (int y = 0; y < BS::MAP_HEIGHT; y++)
        for (int x = 0; x < BS::MAP_WIDTH; x++)
            frameBuffer[y][x] = '~';
}

void Map::renderShip(Ship *ship)
{
    int size = ship->getSize();
    int half = ship->getSize() / 2;
    char toRender;
    // cout << "\nHALF: " << half;
    for (int i = (half * -1); i < half; i++)
    {
        if (i == half * -1)
            toRender = '<';
        else if (i == half - 1)
            toRender = '>';
        else
            toRender = '='; 
    // cout << "\nToRender: " << toRender;
        frameBuffer[ship->getY()][ship->getX() + i] = toRender;
    }
}