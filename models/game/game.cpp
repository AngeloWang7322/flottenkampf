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
    string types[] = {"HUNTER", "DESTROYER", "CRUISER"};
    string attacks[] = {"Critical Hit", "Homing Missile", "Bombardement"};
    int hp[] = {BS::HUNTER_HP, BS::DESTROYER_HP, BS::CRUISER_HP};
    int dmg[] = {BS::HUNTER_DMG, BS::DESTROYER_DMG, BS::CRUISER_DMG};
    int costs[] = {BS::HUNTER_SIZE, BS::DESTROYER_SIZE, BS::CRUISER_SIZE};
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
            string ACount = i == hoveredA
                                ? Utils::colorize("- " + to_string(countsA[i]) + " +", TextStyle::RED)
                                : "- " + to_string(countsA[i]) + " +";
            string BCount = i == hoveredB
                                ? Utils::colorize("- " + to_string(countsB[i]) + " +", TextStyle::RED)
                                : "- " + to_string(countsB[i]) + " +";

            string tempLine = +" [ " + types[i] + "($" + to_string(costs[i]) + ") " + to_string(hp[i]) + "Hp | " + to_string(dmg[i]) + "Dmg !" + attacks[i] + "! ] ";

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
                costs);
        if (Utils::isInputB(input))
            this->handleFleetSelectionInput(
                Utils::parseInputB(input),
                &hoveredB,
                &budgetB,
                &isReadyB,
                countsB,
                costs);
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
    int costs[])
{
    if (input == Action::EXECUTE)
        *isReady = !*isReady;

    if (*isReady)
        return;

    switch (input)
    {
    case Action::UP:
        *hovered = max(0, (*hovered - 1));
        break;
    case Action::DOWN:
        *hovered = min(2, (*hovered + 1));
        break;
    case Action::LEFT:
    {
        if (counts[*hovered] == 0)
            break;

        counts[*hovered]--;
        *budget += costs[*hovered];
        break;
    }
    case Action::RIGHT:
    {
        if (*budget - costs[*hovered] < 0)
            break;

        counts[*hovered]++;
        *budget -= costs[*hovered];
        break;
    }
    }
}
void Game::start()
{
    state = GameState::FIGHTING;
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
    chrono::milliseconds interval = chrono::milliseconds(1000 / BS::FRAMERATE);
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