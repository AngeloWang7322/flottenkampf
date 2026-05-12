#include <stdio.h>
#include <iostream>
#include "fleet.h"
#include "../ship/ship.h"
#include "../ship/cruiser/cruiser.h"
#include "../../constants/BalanceSheet.cpp"
#include "../utils/utils.h"

using namespace std;

Fleet::Fleet()
{
}

void Fleet::addShip(Ship *ship)
{
    ship->setY(this->ships.size());
    this->ships.push_back(ship);
}
void Fleet::addShip(int shipCode)
{

    switch (shipCode)
    {
    case 2:
        this->addShip(new Cruiser());
    }
}
void Fleet::choose()
{
    int hovered = 0;
    string types[] = {"HUNTER", "DESTROYER", "CRUISER"};
    string attacks[] = {"Critical Hit", "Homing Missile", "Bombardement"};
    int hp[] = {BS::HUNTER_HP, BS::DESTROYER_HP, BS::CRUISER_HP};
    int dmg[] = {BS::HUNTER_DMG, BS::DESTROYER_DMG, BS::CRUISER_DMG};
    int costs[] = {BS::HUNTER_SIZE, BS::DESTROYER_SIZE, BS::CRUISER_SIZE};
    int counts[] = {0, 0, 0};
    int budget = BS::FLEET_BUDGET;
    char input = 'x';

    while (input != '\n')
    {
        system("clear");
        cout << "Budget: $" << budget;
        for (int i = 0; i < 3; i++)
        {
            string tempLine = "\n" + types[i] + "($" + to_string(costs[i]) + ") " + to_string(hp[i]) + "Hp | " + to_string(dmg[i]) + "Dmg !" + attacks[i] + "!: - " + to_string(counts[i]) + " +";
            if (i == hovered)
                tempLine = Utils::colorize(tempLine, TextStyle::RED);
            cout << tempLine;
        }

        input = Utils::readInput();
        switch (input)
        {
        case 'w':
            hovered = max(0, (hovered - 1));
            break;
        case 's':
            hovered = min(2, (hovered + 1));
            break;
        case 'a':
        {
            if (counts[hovered] == 0)
                break;

            counts[hovered]--;
            budget += costs[hovered];
            break;
        }
        case 'd':
        {
            if (budget - costs[hovered] < 0)
                break;

            counts[hovered]++;
            budget -= costs[hovered];
            break;
        }
        }
    }

    for (int i = 2; i >= 0; i--)
        for (int j = 0; j < counts[i]; j++)
            this->addShip(i);
}

Ship *Fleet::getShip(int index)
{
    return this->ships[index];
}
vector<Ship *> Fleet::getShips()
{
    return this->ships;
}