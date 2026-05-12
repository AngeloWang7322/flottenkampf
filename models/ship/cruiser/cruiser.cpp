#include <stdio.h>
#include <iostream>
#include "cruiser.h"
#include "../../../constants/BalanceSheet.cpp"

Cruiser::Cruiser(bool isLeft) : Ship()
{
    this->size = BS::CRUISER_SIZE;
    this->hp = BS::CRUISER_HP;
    this->dmg = BS::CRUISER_DMG;
    this->x = isLeft
                  ? this->size / 2
                  : BS::MAP_WIDTH - (this->size / 2);
}
bool Cruiser::attack()
{
    return true;
}