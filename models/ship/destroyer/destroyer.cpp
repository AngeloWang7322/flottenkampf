#include <stdio.h>
#include <iostream>
#include "destroyer.h"
#include "../../../constants/BalanceSheet.cpp"

Destroyer::Destroyer() : Ship()
{
    this->size = BS::DESTROYER_SIZE;
    this->hp = BS::DESTROYER_HP;
    this->dmg = BS::DESTROYER_DMG;
}

bool Destroyer::attack()
{
    return true;
}