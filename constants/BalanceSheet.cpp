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
    double accuracy;
};
class BS
{
public:
    inline static const int FPS = 24;

    inline static const int MAP_WIDTH = 50;
    inline static const int MAP_HEIGHT = 10;
    inline static const int SPAWN_OFFSET = 2;
    inline static const int FLEET_BUDGET = 25;

    inline static const ShipStats HUNTER_STATS = ShipStats{"Hunter", "Critical Hit", 3, 75, 30, 1.5, 10, 25, 0.5};
    inline static const ShipStats DESTROYER_STATS = ShipStats{"Destroyer", "Homing Missile", 5, 150, 50, 3, 6, 15, 0.7};
    inline static const ShipStats CRUISER_STATS = ShipStats{"Cruiser", "Bombardement", 7, 250, 75, 5, 3, 50, 0.9};
};
#endif