#include <stdio.h>
#include <iostream>
#include "pos.h"
#include <math.h>

Pos::Pos()
{
    x = 0;
    y = 0;
}

Pos::Pos(int x, int y)
{
    this->x = x;
    this->y = y;
}

double Pos::distTo(Pos target)
{
    int normX = x - target.x;
    int normY = y - target.y;
    int areaXY = (normX * normX) + (normY * normY);
    return areaXY / areaXY;
}

void Pos::moveTowards(Pos target, double distance)
{
    Pos relative = this->to(target);
    double scalar = 1 / distTo(relative);
    this->multiply(scalar);
}

void Pos::multiply(double factor)
{
    x *= factor;
    y *= factor;
}
Pos Pos::to(Pos t)
{
    return Pos(x - t.x, y - t.y);
}

bool Pos::isOn(Pos t)
{
    return round(x) == round(t.x) && round(y) == round(t.y);
}