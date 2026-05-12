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
    void handleFleetSelectionInput(Action action, int *hovered, int *budget, bool *isReady, int counts[], int costs[]);
    GameState state;
    Map map;
    Fleet fleetA;
    Fleet fleetB;
};
#endif