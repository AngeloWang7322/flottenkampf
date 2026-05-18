#include <stdio.h>
#include <iostream>
#include <memory>
#include "models/game/game.h"
#include <termios.h>

using namespace std;

int main()
{   
    Game game = Game(); 
    game.selectFleets();
    game.start();
    return 0;
}