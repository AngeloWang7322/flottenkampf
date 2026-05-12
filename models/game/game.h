#ifndef GAME_H
#define GAME_H
#include "../map/map.h"

class Game
{
public:
    Game(); 
    void selectFleets();
    void start();
private:
    char readInput();
    string colorize(string, TextStyle);
    GameState state;
    Map map;
    Fleet fleetA;
    Fleet fleetB;
};
#endif