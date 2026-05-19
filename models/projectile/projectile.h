#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <string>
#include "../pos/pos.h"
#include "../map/map.h"

class Map;
class Projectile
{
public:
    Projectile() = default;
    Projectile(Pos pos, Pos target, double velocity);
    bool launch();
    bool isActive();
    std::string getDisplay();
    Pos getPos();

private:
    Pos pos;
    Pos target;
    double velocity;
    bool active;
};
#endif