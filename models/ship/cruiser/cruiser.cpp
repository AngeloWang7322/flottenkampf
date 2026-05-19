#include <stdio.h>
#include <iostream>
#include "cruiser.h"
#include "../../../constants/BalanceSheet.cpp"

Cruiser::Cruiser() : Ship()
{
    this->stats = BS::CRUISER_STATS;
}

bool Cruiser::launchProjectile(Ship* ship)
{
    return true;
}