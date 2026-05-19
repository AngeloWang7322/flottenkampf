#include <stdio.h>
#include <iostream>
#include "projectile.h"
#include <chrono>
#include <thread>
#include <math.h>

using namespace std;

Projectile::Projectile(Pos pos, Pos target, double velocity, Map &map) : pos(pos),
                                                                         target(target),
                                                                         velocity(velocity),
                                                                         map(map),
                                                                         active(true)
{
    start();
}

bool Projectile::start()
{
    chrono::milliseconds interval = chrono::milliseconds(static_cast<int64_t>(1000 * velocity));
    while (active)
    {
        pos.moveTowards(target);

        if (pos.isOn(target))
            active = false;

        this_thread::sleep_for(interval);
    }
    return true;
}
char Projectile::getDisplay()
{
    if (!active)
        return 'X';

    int xDir = pos.x - target.x;
    int yDir = pos.y - target.y;

    if (xDir > yDir)
        return xDir > 0 ? '>'
                        : '<';
    else
        return yDir > 0 ? '^'
                        : 'v';
}