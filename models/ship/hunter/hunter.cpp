#include <stdio.h>
#include <iostream>
#include "hunter.h"
#include "../../../constants/BalanceSheet.cpp"

Hunter::Hunter() : Ship()
{
    this->size = BS::HUNTER_SIZE;
    this->hp = BS::HUNTER_HP;
    this->dmg = BS::HUNTER_DMG;
}

bool Hunter::attack()
{
    return true;
}