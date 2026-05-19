#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "game.h"
#include "../map/map.h"
#include "../../constants/BalanceSheet.cpp"
#include "../utils/utils.h"

using namespace std;

Game::Game() : map(), fleetA(this->map), fleetB(this->map)
{
    this->map.setFleets(&fleetA, &fleetB);
    this->state = GameState::FLEETCREATION;
}

void Game::selectFleets()
{
    ShipStats stats[] = {BS::HUNTER_STATS, BS::DESTROYER_STATS, BS::CRUISER_STATS};
    int hoveredA = 0;
    int hoveredB = 0;
    int budgetA = BS::FLEET_BUDGET;
    int budgetB = BS::FLEET_BUDGET;
    int countsA[] = {0, 0, 0};
    int countsB[] = {0, 0, 0};
    bool isReadyA = false;
    bool isReadyB = false;
    char input = ' ';
    while (!isReadyA || !isReadyB)
    {
        system("clear");

        for (int i = 0; i < 3; i++)
        {
            string ACount = i == hoveredA || isReadyA
                                ? Utils::colorize("- " + to_string(countsA[i]) + " +", TextStyle::YELLOW)
                                : "- " + to_string(countsA[i]) + " +";
            string BCount = i == hoveredB || isReadyB
                                ? Utils::colorize("- " + to_string(countsB[i]) + " +", TextStyle::YELLOW)
                                : "- " + to_string(countsB[i]) + " +";

            string tempLine = +" [ " + stats[i].name + "($" + to_string(stats[i].size) + ") " + to_string(stats[i].hp) + "HP | " + to_string(stats[i].dmg) + "Dmg !" + stats[i].ability + "! ] ";

            cout << ACount << tempLine << BCount << std::endl;
        }

        input = Utils::readInput();

        if (Utils::isInputA(input))
            handleFleetSelectionInput(
                Utils::parseInputA(input),
                &hoveredA,
                &budgetA,
                &isReadyA,
                countsA,
                stats);
        if (Utils::isInputB(input))
            this->handleFleetSelectionInput(
                Utils::parseInputB(input),
                &hoveredB,
                &budgetB,
                &isReadyB,
                countsB,
                stats);
    }
    for (int i = 2; i >= 0; i--)
        for (int j = 0; j < countsA[i]; j++)
            this->fleetA.addShip(i);

    for (int i = 2; i >= 0; i--)
        for (int j = 0; j < countsB[i]; j++)
            this->fleetB.addShip(i);

    this->fleetA.align(0);
    this->fleetB.align(-1);
}

void Game::handleFleetSelectionInput(
    Action input,
    int *hovered,
    int *budget,
    bool *isReady,
    int counts[],
    ShipStats stats[])
{
    int count = counts[0] + counts[1] + counts[2];
    if (input == Action::EXECUTE && count != 0)
        *isReady = !*isReady;

    if (*isReady)
        return;

    switch (input)
    {
    case Action::UP:
        *hovered = (*hovered - 1) % 3;
        break;
    case Action::DOWN:
        *hovered = (*hovered + 1) % 3;
        break;
    case Action::LEFT:
    {
        if (counts[*hovered] == 0)
            break;

        counts[*hovered]--;
        *budget += stats[*hovered].size;
        break;
    }
    case Action::RIGHT:
    {
        if (*budget - stats[*hovered].size < 0)
            break;

        counts[*hovered]++;
        *budget -= stats[*hovered].size;
        break;
    }
    }
}
void Game::start()
{
    state = GameState::FIGHTING;
    fleetA.startAttacking(&fleetB);
    fleetB.startAttacking(&fleetA);
    thread frameTicker([this]()
                       { startFrameTicker(); });
    char input;
    Fleet *actingFleet;
    Action action;

    while (state == GameState::FIGHTING)
    {
        input = Utils::readInput();
        if (!parseInput(input, &actingFleet, &action))
            continue;

        actingFleet->execute(action);
    }
}

void Game::startFrameTicker()
{
    chrono::milliseconds interval = chrono::milliseconds(1000 / BS::FPS);
    while (state == GameState::FIGHTING)
    {
        system("clear");
        this->map.printFrame();
        this_thread::sleep_for(interval);
    }
}

bool Game::parseInput(char input, Fleet **actingFleet, Action *action)
{
    if (Utils::isInputA(input))
    {
        *actingFleet = &fleetA;
        *action = Utils::parseInputA(input);
        return true;
    }
    else if (Utils::isInputB(input))
    {
        *actingFleet = &fleetB;
        *action = Utils::parseInputB(input);
        return true;
    }
    return false;
}