#include <stdio.h>
#include <iostream>
#include "destroyer.h"
#include "../../../constants/BalanceSheet.cpp"

Destroyer::Destroyer() : Ship()
{
    this->stats = BS::DESTROYER_STATS;
}

bool Destroyer::launchProjectile(Ship* ship)
{
    return true;
}