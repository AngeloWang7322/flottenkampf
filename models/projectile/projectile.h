#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "../pos/pos.h"
#include "../map/map.h"
class Map;
class Projectile
{
public:
    Projectile(Pos pos, Pos target, double velocity);
    bool launch();
    char getDisplay();
    Pos getPos();

private:
    Pos pos;
    Pos target;
    double velocity;
    bool active;
};
#endif