#include <stdio.h>
#include <iostream>
#include <termios.h>
#include "game.h"
#include "../ship/cruiser/cruiser.h"
#include "../../constants/BalanceSheet.cpp"
using namespace std;

Game::Game()
{
    this->fleetA = Fleet();
    this->fleetB = Fleet();
    this->map = Map();
    this->state = GameState::FLEETCREATION;
}
void Game::start()
{
    this->state = GameState::MOVING;
    this->map.renderFleet(this->fleetA);
    this->map.renderFleet(this->fleetB);
    this->map.print();
}
void Game::selectFleets()
{
    int hovering = 0;
    int HunCount = 0, DesCount = 0, CruCount = 0;

    cout << "TYPE:  HP | DMG | SPECIAL ATTACK\n";
    // if (hovering == 0)
    //     cout << "\e[1;97m";
    cout << "HUNTER: " << BS::HUNTER_HP << " | " << BS::HUNTER_DMG << " | Critical Hit ==> - " << HunCount << " +\n";
    cout << "DESTROYER: " << BS::DESTROYER_HP << " | " << BS::DESTROYER_DMG << " | Target Seeking ==> - " << DesCount << +" +\n";
    cout << "CRUISER: " << BS::CRUISER_HP << " | " << BS::CRUISER_DMG << " | Bombardement ==> - " << CruCount << " +\n";

    this->fleetA.addShip(new Cruiser());
    this->fleetA.addShip(new Cruiser());
    this->fleetB.addShip(new Cruiser());
    this->fleetB.getShip(0)->setX(BS::MAP_WIDTH - 3);
}
void Game::readInput(){
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char c = getChar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c
}