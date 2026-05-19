#ifndef BALANCESHEET_H
#define BALANCESHEET_H
#include <string>

struct ShipStats
{
    std::string name;
    std::string ability;
    int size;
    int hp;
    int dmg;
    double firerate;
    double velocity;
    int range;
};
class BS
{
public:
    inline static const int MAP_WIDTH = 50;
    inline static const int MAP_HEIGHT = 10;
    inline static const int SPAWN_OFFSET = 2;
    inline static const int FRAMERATE = 24;
    inline static const int FLEET_BUDGET = 25;

    inline static const ShipStats HUNTER_STATS = ShipStats{"Hunter", "Critical Hit", 3, 75, 30, 2, 3, 25};
    inline static const ShipStats DESTROYER_STATS = ShipStats{"Destroyer", "Homing Missile", 5, 150, 50, 3, 3, 15};
    inline static const ShipStats CRUISER_STATS = ShipStats{"Cruiser", "", 7, 250, 75, 5, 2, 50};
};
#endif