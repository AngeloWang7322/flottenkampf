#pragma once
#ifndef GAME_H
#define GAME_H
#include "../fleet/fleet.h"
#include <mutex>

enum GameState;
class Game
{
public:
    Game();
    void selectFleets();
    void start();

private:
    void handleFleetSelectionInput(Action action, int *hovered, int *budget, bool *isReady, int counts[], int costs[]);
    void startFrameTicker();
    bool parseInput(char, Fleet**, Action*);
    std::mutex game;
    GameState state;
    Map map;
    Fleet fleetA;
    Fleet fleetB;
};
#endif