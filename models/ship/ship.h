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
    int getStart();
    int getEnd();
    std::vector<Projectile*> getProjectiles();
    void attack(Fleet *);
    void setX(int val);
    void setY(int val);
    Pos getPos();
    int getX();
    int getY();
    ShipStats getStats();
    ShipState getState();
    bool isActive();

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