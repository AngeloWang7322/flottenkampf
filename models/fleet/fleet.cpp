#include <stdio.h>
#include <iostream>
#include "fleet.h"
#include "../ship/ship.h"

using namespace std;

Fleet::Fleet()
{
    
}

void Fleet::addShip(Ship *ship)
{
    ship->setY(this->ships.size());
    this->ships.push_back(ship);
}

Ship *Fleet::getShip(int index)
{
    return this->ships[index];
}
vector<Ship*>Fleet::getShips()
{
    return this->ships;
}