#include <stdio.h>
#include <iostream>
#include "hunter.h"
#include "../../../constants/BalanceSheet.cpp"

Hunter::Hunter() : Ship()
{
    this->stats = BS::HUNTER_STATS;
}

bool Hunter::launchProjectile(Ship *target)
{
    return true;
}