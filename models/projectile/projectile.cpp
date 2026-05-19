#include <stdio.h>
#include <iostream>
#include "projectile.h"
#include <chrono>
#include <thread>
#include <math.h>
#include <random>
#include <string>
#include "../map/map.h"

using namespace std;

Projectile::Projectile(Pos pos, Pos target, double velocity) : pos(pos.x, pos.y),
                                                               target(target.x, target.y),
                                                               velocity(velocity),
                                                               active(true)
{
}

bool Projectile::launch()
{
    int interval = 1000 / velocity;
    for (int i = 0; i < pos.distTo(target); i++)
    {
        this_thread::sleep_for(chrono::milliseconds(interval));

        pos.moveTowards(target);
        if (pos.isOn(target))
        {
            active = false;
            break;
        }
    }
    return true;
}

string Projectile::getDisplay()
{
    if (!active)
        return "X";

    int xDir = target.x - pos.x;
    int yDir = target.y - pos.y;

    if (abs(xDir) > abs(yDir))
        return xDir > 0 ? ">"
                        : "<";
    else
        return yDir > 0 ? "v"
                        : "^";
}

bool Projectile::isActive() { return active; }

Pos Projectile::getPos() { return pos; }