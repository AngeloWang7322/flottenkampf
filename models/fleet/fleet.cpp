#include <stdio.h>
#include <iostream>
#include "fleet.h"
#include "../ship/ship.h"
#include "../ship/hunter/hunter.h"
#include "../ship/destroyer/destroyer.h"
#include "../ship/cruiser/cruiser.h"
#include "../../constants/BalanceSheet.cpp"
#include "../utils/utils.h"

using namespace std;

Fleet::Fleet()
{
}

void Fleet::addShip(Ship *ship)
{
    ship->setY(this->ships.size());
    this->ships.push_back(ship);
}
void Fleet::addShip(int shipCode)
{
    switch (shipCode)
    {
    case 0:
        this->addShip(new Hunter());
        break;
    case 1:
        this->addShip(new Destroyer());
        break;
    case 2:
        this->addShip(new Cruiser());
        break;
    }
}

void Fleet::align(int pos)
{
    int border, sign;
    if (pos >= 0)
    {
        border = pos + BS::SPAWN_OFFSET;
        sign = 1;
    }
    else
    {
        border = pos + BS::MAP_WIDTH - BS::SPAWN_OFFSET;
        sign = -1;
    }
    for (Ship *ship : this->ships)
        ship->setX(border + ((ship->getSize() / 2) * sign));
}

Ship *Fleet::getShip(int index)
{
    return this->ships[index];
}

vector<Ship *> Fleet::getShips()
{
    return this->ships;
}