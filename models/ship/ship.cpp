#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>
#include "ship.h"
#include "../fleet/fleet.h"

using namespace std;

Ship::Ship()
{
    this->active = true;
    this->pos = Pos();
    this->state = ShipState::IDLE;
    this->firerate = 0.5;
}

void Ship::move(Pos move)
{
    pos.x = min(max(static_cast<int>(pos.x + move.x), 0), BS::MAP_WIDTH - 1);
    pos.y = min(max(static_cast<int>(pos.y + move.y), 0), BS::MAP_HEIGHT - 1);
}

int Ship::getStart()
{
    return pos.x - (size / 2);
}

int Ship::getEnd()
{
    return pos.x + (size / 2);
}

void Ship::startAttacking(Fleet fleet)
{
    chrono::milliseconds interval = chrono::milliseconds(1000 * firerate);
    while (active)
    {
        Ship *target = getTargetShip(fleet);
        attack(target);
        this_thread::sleep_for(interval);
    }
}

Ship *Ship::getTargetShip(Fleet fleet)
{
    int closestDist;
    Ship *closestShip = nullptr;

    for (Ship *ship : fleet.getShips())
    {
        int distance = pos.distTo(ship->getPos());

        if (distance < range &&
            (closestShip == nullptr || distance < closestDist))
        {
            closestShip = ship;
            closestDist = distance;
        }
    }
    return closestShip;
}
Pos Ship::getPos()
{
    return pos;
}
void Ship::setX(int val)
{
    this->pos.x = val;
}

void Ship::setY(int val)
{
    this->pos.y = val;
}

int Ship::getX()
{
    return this->pos.x;
}

int Ship::getY()
{
    return this->pos.y;
}
int Ship::getSize()
{
    return this->size;
}
ShipState Ship::getState()
{
    return state;
}
bool Ship::isActive()
{
    return active;
}