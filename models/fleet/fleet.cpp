#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>
#include "fleet.h"
#include "../map/map.h"
#include "../ship/ship.h"
#include "../ship/hunter/hunter.h"
#include "../ship/destroyer/destroyer.h"
#include "../ship/cruiser/cruiser.h"
#include "../../constants/BalanceSheet.cpp"
#include "../utils/utils.h"

using namespace std;

Fleet::Fleet(Map &map) : map(map)
{
    active = 0;
}

void Fleet::addShip(Ship *ship)
{
    ship->setY(this->ships.size());
    this->ships.push_back(ship);
}

void Fleet::startAttacking(Fleet *targetFleet)
{
    for (Ship *ship : this->ships)
    {
        thread t([ship, targetFleet]()
                 { ship->attack(targetFleet); });
        t.detach();
    }
}

bool Fleet::tryMoveShip(Pos move, Ship *ship)
{
    int shipStart = ship->getStart() + move.x;
    int shipEnd = ship->getEnd() + move.x;
    int shipY = ship->getPos().y + move.y;

    if (map.areaIsEmpty(shipStart, shipEnd, shipY, shipY, ship))
    {
        ship->move(move);
        return true;
    }
    return false;
}

bool Fleet::execute(Action action)
{
    switch (action)
    {
    case Action::UP:
        return tryMoveShip(Pos(0, -1), getActiveShip());
    case Action::DOWN:
        return tryMoveShip(Pos(0, 1), getActiveShip());
    case Action::LEFT:
        return tryMoveShip(Pos(-1, 0), getActiveShip());
    case Action::RIGHT:
        return tryMoveShip(Pos(1, 0), getActiveShip());
    case Action::EXECUTE:
    {
        changeActive();
        return true;
    }
    default:
        return true;
    }
}

void Fleet::changeActive()
{
    do
    {
        active = (active + 1) % ships.size();
    } while (!getActiveShip()->isActive());
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
    for (int i = 0; i < this->ships.size(); i++)
    {
        Ship *curShip = this->ships.at(i);
        curShip->setX(border + ((curShip->getStats().size / 2) * sign));
        curShip->setY((BS::MAP_HEIGHT / 2) + (((i) / 2) + ((i % 2) * -1) * i));
    }
}

void Fleet::setActive(int)
{
    active = 0;
}
int Fleet::getActive()
{
    return active;
}

Ship *Fleet::getActiveShip()
{
    return ships.at(active);
}

Ship *Fleet::getShip(int index)
{
    return this->ships[index];
}

vector<Ship *> Fleet::getShips()
{
    return ships;
}