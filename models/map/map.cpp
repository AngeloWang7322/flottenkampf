#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "map.h"
#include "../projectile/projectile.h"
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

array<array<Ship *, BS::MAP_WIDTH>, BS::MAP_HEIGHT> Map::getShipMap()
{
    array<array<Ship *, BS::MAP_WIDTH>, BS::MAP_HEIGHT> shipMap{};

    for (Ship *ship : getAllShips())
    {
        int y = ship->getPos().y;
        for (int x = ship->getStart(); x < ship->getEnd(); x++)
            shipMap[y][x] = ship;
    }
    return shipMap;
}

void Map::setFleets(Fleet *fleetA, Fleet *fleetB)
{
    this->fleetA = fleetA;
    this->fleetB = fleetB;
}

vector<Ship *> Map::getAllShips()
{
    vector<Ship *> allShips;
    for (Ship *ship : fleetA->getShips())
        allShips.push_back(ship);
    for (Ship *ship : fleetB->getShips())
        allShips.push_back(ship);
    return allShips;
}
void Map::printFrame()
{
    resetFrame();
    renderFleet(*fleetA);
    renderFleet(*fleetB);
    renderProjectiles();
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
void Map::renderProjectiles()
{
    for (Ship *ship : getAllShips())
    {
        for (Projectile *p : ship->getProjectiles())
        {
            int x = round(p->getPos().x);
            int y = round(p->getPos().y);
            frameBuffer[y][x] = p->getDisplay();
        }
    }
}
bool Map::areaIsEmpty(int fromX, int toX, int fromY, int toY, Ship *ignore)
{
    auto shipMap = getShipMap();
    for (int y = fromY; y <= toY; y++)
        for (int x = fromX; x < toX; x++)
            if (isOutOfMap(x, y) ||
                (shipMap[y][x] != ignore &&
                 shipMap[y][x] != nullptr))
                return false;

    return true;
}

bool Map::isOutOfMap(int x, int y)
{
    return (x < 0 || x >= BS::MAP_WIDTH) || (y < 0 || y >= BS::MAP_HEIGHT);
}

void Map::resetFrame()
{
    for (int y = 0; y < BS::MAP_HEIGHT; y++)
        for (int x = 0; x < BS::MAP_WIDTH; x++)
            frameBuffer[y][x] = Utils::colorize("~", TextStyle::BLUE);
}

void Map::renderShip(Ship *ship, bool isActive)
{
    int size = ship->getStats().size;
    int half = ceil(ship->getStats().size / 2);
    TextStyle shipColor = isActive
                              ? TextStyle::YELLOW
                              : Utils::shipStateToColor(ship->getState());
    string toRender;
    for (int i = (half * -1); i <= half; i++)
    {
        if (i == half * -1)
            toRender = '<';
        else if (i == half)
            toRender = '>';
        else if (i == 0)
            toRender = 'H';
        else
            toRender = '=';
        frameBuffer[ship->getY()][ship->getX() + i] = Utils::colorize(toRender, shipColor);
    }
}
