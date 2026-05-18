#pragma once
#ifndef SHIP_H
#define SHIP_H
#include "../types.h"
#include "../pos/pos.h"

class Fleet;
class Ship
{
public:
    Ship();
    ~Ship() = default;
    void startAttacking(Fleet);
    void setX(int val);
    void setY(int val);
    Pos getPos();
    int getX();
    int getY();
    int getSize();
    ShipState getState();
    bool isActive();

protected:
    Ship *getTargetShip(Fleet);
    virtual bool attack(Ship *) = 0;
    bool active;
    int size;
    int dmg;
    int hp;
    int range;
    int firerate;
    Pos pos;
    ShipState state;
};
#endif