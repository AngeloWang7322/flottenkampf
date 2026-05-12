#include <stdio.h>
#include <iostream>
#include <memory>
#include "models/fleet/fleet.h"
#include "models/game/game.h"
#include "models/ship/cruiser/cruiser.h"
#include <termios.h>
using namespace std;
int main()
{   
    vector<char> selectionA;
    vector<char> selectionB;
    Game game = Game();
    game.selectFleets();
    game.start();
    return 0;
}