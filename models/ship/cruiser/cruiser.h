#pragma once
#ifndef CRUISER_H
#define CRUISER_H
#include "../ship.h"

class Cruiser : public Ship
{
public:
    Cruiser();
    bool launchProjectile(Ship *ship);

private:
};
#endif