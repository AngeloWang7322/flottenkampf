#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>
#include "ship.h"
#include "../projectile/projectile.h"
#include "../fleet/fleet.h"
#include "../../constants/BalanceSheet.cpp"

struct ShipStats;
using namespace std;

Ship::Ship()
{
    this->active = true;
    this->pos = Pos();
    this->state = ShipState::IDLE;
}

void Ship::move(Pos move)
{
    pos.add(move);
    pos.clampToEdge();
}
vector<Projectile *> Ship::getProjectiles()
{
    return projectiles;
}
int Ship::getStart()
{
    return pos.x - (stats.size / 2);
}

int Ship::getEnd()
{
    return pos.x + (stats.size / 2);
}

void Ship::attack(Fleet *fleet)
{
    chrono::milliseconds interval = chrono::milliseconds(static_cast<int>(1000 * stats.firerate));
    while (active)
    {
        this_thread::sleep_for(interval);
        Ship *target = getTargetShip(fleet);
        if (target == nullptr)
            continue;
        Projectile *projectile = new Projectile(pos, target->getPos(), 3);
        projectiles.push_back(projectile);

        thread t([projectile]()
                 { projectile->launch(); });
        t.detach();
    }
}

Ship *Ship::getTargetShip(Fleet *fleet)
{
    int closestDist;
    Ship *closestShip = nullptr;
    for (Ship *ship : fleet->getShips())
    {
        int distance = pos.distTo(ship->getPos());

        if (distance < stats.range &&
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
ShipStats Ship::getStats()
{
    return this->stats;
}
ShipState Ship::getState()
{
    return state;
}
bool Ship::isActive()
{
    return active;
}