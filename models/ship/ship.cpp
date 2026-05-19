#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>
#include <random>
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

void Ship::attack(Fleet *fleet)
{
    int interval = 1000 * stats.firerate;
    int variedInterval;

    while (active)
    {
        variedInterval = interval + rand() % 200;
        this_thread::sleep_for(chrono::milliseconds(variedInterval));

        Ship *target = getTargetShip(fleet);
        if (target == nullptr)
            continue;

        double randFac = pos.distTo(target->pos) * (1.0 - stats.accuracy);
        Pos targetPos = target->getPos();
        targetPos.randomize(randFac);
        targetPos.clampToEdge();

        Projectile *projectile = new Projectile(this->pos, targetPos, stats.velocity);
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

Pos Ship::getPos() { return pos; }

ShipStats Ship::getStats() { return this->stats; }

ShipState Ship::getState() { return state; }

bool Ship::isActive() { return active; }

int Ship::getStart() { return pos.x - (stats.size / 2); }

int Ship::getEnd() { return pos.x + (stats.size / 2); }

vector<Projectile *> Ship::getProjectiles() { return projectiles; }

void Ship::setPos(Pos p)
{
    pos = p;
}