#ifndef HUNTER_H
#define HUNTER_H
#include "../ship.h"

class Hunter : public Ship
{
    public:
    Hunter();
    bool attack();
};
#endif