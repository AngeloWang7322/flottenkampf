#include <stdio.h>
#include <iostream>
#include "map.h"
#include "../fleet/fleet.h"
#include "../utils/utils.h"
#include "../../constants/BalanceSheet.cpp"

using namespace std;

Map::Map()
{
    fleetA = nullptr;
    fleetB = nullptr;
    this->resetFrame();
}

void Map::printFrame()
{
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
    for (int i = 0; i < fleet.getShips().size(); i++)
    {
        bool isActive = fleet.getActive() == i;
        renderShip(fleet.getShip(i), isActive);
    }
}

void Map::resetFrame()
{
    for (int y = 0; y < BS::MAP_HEIGHT; y++)
        for (int x = 0; x < BS::MAP_WIDTH; x++)
            frameBuffer[y][x] = Utils::colorize("~", TextStyle::BLUE);
}

void Map::renderShip(Ship *ship, bool isActive)
{
    int size = ship->getSize();
    int half = (ship->getSize() / 2);
    TextStyle shipColor = isActive
                              ? TextStyle::YELLOW
                              : Utils::shipStateToColor(ship->getState());
    string toRender;
    for (int i = (half * -1); i < half; i++)
    {
        if (i == half * -1)
            toRender = '<';
        else if (i == half - 1)
            toRender = '>';
        else
            toRender = '=';
        frameBuffer[ship->getY()][ship->getX() + i] = Utils::colorize(toRender, shipColor);
    }
}
