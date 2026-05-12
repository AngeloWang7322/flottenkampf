#include <stdio.h>
#include <iostream>
#include <string>
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

void Game::selectFleets()
{
    this->state = GameState::FLEETCREATION;
    this->fleetA.choose();
    printf("fleetA size: " + this->fleetA.getShips().size());
    this->fleetB.choose();
    printf("fleetB size: " + this->fleetB.getShips().size());
}

void Game::start()
{
    this->state = GameState::MOVING;
    this->map.renderFleet(this->fleetA);
    this->map.renderFleet(this->fleetB);
    this->map.print();
}