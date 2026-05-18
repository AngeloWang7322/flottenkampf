#ifndef BALANCESHEET_H
#define BALANCESHEET_H
class BS
{
public:
    inline static const int MAP_WIDTH = 50;
    inline static const int MAP_HEIGHT = 10;
    inline static const int SPAWN_OFFSET = 2;
    inline static const int FRAMERATE = 24; 
    inline static const int FLEET_BUDGET = 25;
    
    inline static const int HUNTER_SIZE = 4;
    inline static const int DESTROYER_SIZE = 6;
    inline static const int CRUISER_SIZE = 8;
    inline static const int HUNTER_HP = 75;
    inline static const int DESTROYER_HP = 150;
    inline static const int CRUISER_HP = 250;
    inline static const int HUNTER_DMG = 30;
    inline static const int DESTROYER_DMG = 60;
    inline static const int CRUISER_DMG = 20;
};
#endif