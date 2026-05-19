#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include "pos.h"
#include "../utils/utils.h"
#include "../../constants/BalanceSheet.cpp"

using namespace std;

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
    int normX = target.x - x;
    int normY = target.y - y;
    int areaXY = (normX * normX) + (normY * normY);
    return sqrt(areaXY);
}

void Pos::moveTowards(Pos target, double distance)
{
    Pos relative = this->to(target);
    double scalar = distance / distTo(target);
    relative.multiply(scalar);
    this->add(relative);
    this->clampToEdge();
}

void Pos::multiply(double factor)
{
    x *= factor;
    y *= factor;
}

void Pos::add(Pos p)
{
    x += p.x;
    y += p.y;
}

void Pos::clampToEdge()
{
    x = min(max(x, 0.0), BS::MAP_WIDTH - 1.0);
    y = min(max(y, 0.0), BS::MAP_HEIGHT - 1.0);
}

void Pos::randomize(double fac)
{
    int sign;
    fac *= 100.0;

    sign = Utils::randSign();
    x += (rand() % (int)fac) * sign / 100;
    sign = Utils::randSign();
    y += (rand() % (int)fac) * sign / 100;
}

Pos Pos::to(Pos t)
{
    return Pos(t.x - x, t.y - y);
}

bool Pos::isOn(Pos t) { return round(x) == round(t.x) && round(y) == round(t.y); }