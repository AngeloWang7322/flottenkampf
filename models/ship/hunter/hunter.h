#pragma once
#ifndef HUNTER_H
#define HUNTER_H
#include "../ship.h"

class Hunter : public Ship
{
public:
    Hunter();

private:
    bool launchProjectile(Ship *);
};
#endif