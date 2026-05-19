#include <stdio.h>
#include <iostream>
#include "projectile.h"
#include <chrono>
#include <thread>
#include <math.h>
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
    chrono::milliseconds interval = chrono::milliseconds(static_cast<int64_t>(1000 / velocity));
    while (active)
    {
        this_thread::sleep_for(interval);
        pos.moveTowards(target);
        if (pos.isOn(target))
            active = false;
    }
    return true;
}

Pos Projectile::getPos()
{
    return pos;
}

char Projectile::getDisplay()
{
    if (!active)
        return 'X';

    int xDir = target.x - pos.x;
    int yDir = target.y - pos.y;

    if (xDir > yDir)
        return xDir > 0 ? '>'
                        : '<';
    else
        return yDir > 0 ? '^'
                        : 'v';
}