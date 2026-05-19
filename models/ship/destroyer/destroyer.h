#pragma once
#ifndef DESTROYER_H
#define DESTROYER_H
#include "../ship.h"
class Destroyer : public Ship
{
public:
    Destroyer();
    bool launchProjectile(Ship *ship);
};
#endif