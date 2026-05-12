#include <stdio.h>
#include <iostream>
#include "ship.h"

using namespace std;
Ship::Ship()
{
    this->x = 0;
    this->y = 0;
    this->state = ShipState::IDLE;
}

void Ship::setX(int val){
    this->x = val;
}

void Ship::setY(int val){
    this->y = val;
}

int Ship::getX()
{
    return this->x;
}

int Ship::getY()
{
    return this->y;
}
int Ship::getSize()
{
    return this->size;
}