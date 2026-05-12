#include <stdio.h>
#include <iostream>
#include "cruiser.h"
#include "../../../constants/BalanceSheet.cpp"

Cruiser::Cruiser() : Ship()
{
    this->size = BS::CRUISER_SIZE;
    this->hp = BS::CRUISER_HP;
    this->dmg = BS::CRUISER_DMG;
}
bool Cruiser::attack()
{
    return true;
}