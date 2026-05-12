#ifndef SHIP_H
#define SHIP_H
#include "../types.h"
// enum ShipState;
class Ship
{
public:
    Ship();
    ~Ship() = default;
    virtual bool attack() = 0;
    void setX(int val);
    void setY(int val);
    int getX();
    int getY();
    int getSize();
    ShipState getState();
    bool isActive();

protected:
    int size;
    int dmg;
    int hp;
    int x;
    int y;
    ShipState state;
};
#endif