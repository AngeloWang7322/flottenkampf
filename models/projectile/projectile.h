#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "../pos/pos.h"
#include "../map/map.h"
class Map;
class Projectile
{
public:
    Projectile() = default;
    Projectile(Pos pos, Pos target, double velocity, Map& map);
    char getDisplay();
    Pos getPos();

private:
    bool start();
    Map &map;
    Pos pos;
    Pos target;
    double velocity;
    bool active;
};
#endif