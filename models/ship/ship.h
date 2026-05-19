#pragma once
#ifndef SHIP_H
#define SHIP_H
#include <vector>
#include "../types.h"
#include "../pos/pos.h"
#include "../../constants/BalanceSheet.cpp"

using namespace std;

class Fleet;
class Projectile;
class Ship
{
public:
    Ship();
    ~Ship() = default;
    void move(Pos move);
    void attack(Fleet *);
    bool isActive();
    int getStart();
    int getEnd();
    Pos getPos();
    ShipStats getStats();
    ShipState getState();
    std::vector<Projectile *> getProjectiles();
    void setPos(Pos p);

protected:
    virtual bool launchProjectile(Ship *) = 0;
    Ship *getTargetShip(Fleet *);

    Pos pos;
    ShipState state;
    bool active;
    ShipStats stats;
    std::vector<Projectile *> projectiles{};
};
#endif