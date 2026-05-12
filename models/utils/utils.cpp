#include <stdio.h>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include "../types.h"
#include "utils.h"

using namespace std;

string Utils::colorize(string str, TextStyle style)
{
    string code = "\e[0m";
    switch (style)
    {
    case TextStyle::RED:
        code = "\e[0;33m";
        break;
    case TextStyle::YELLOW:
        code = "\e[0;31m";
        break;
    case TextStyle::BLUE:
        code = "\e[0;36m";
        break;
    }
    return code + str + "\e[0m";
}
char Utils::readInput()
{
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

bool Utils::isInputA(char input)
{
    vector<char> validInputs = {'w', 'a', 's', 'd', 'f'};
    return includes(input, validInputs);
}

bool Utils::isInputB(char input)
{
    vector<char> validInputs = {'i', 'j', 'k', 'l', 'h'};
    return includes(input, validInputs);
}

Action Utils::parseInputA(char input)
{
    switch (input)
    {
    case 'w':
        return Action::UP;
    case 'a':
        return Action::LEFT;
    case 's':
        return Action::DOWN;
    case 'd':
        return Action::RIGHT;
    case 'f':
        return Action::EXECUTE;
    default:
        throw "adsd";
    }
}

Action Utils::parseInputB(char input)
{
    switch (input)
    {
    case 'i':
        return Action::UP;
    case 'j':
        return Action::LEFT;
    case 'k':
        return Action::DOWN;
    case 'l':
        return Action::RIGHT;
    case 'h':
        return Action::EXECUTE;
    default:
        throw "adsd";
    }
}

template <typename T>
bool Utils::includes(const T &needle, const vector<T> &haystack)
{
    for (const auto &entry : haystack)
        if (entry == needle)
            return true;

    return false;
}
TextStyle Utils::shipStateToColor(ShipState state)
{
    switch (state)
    {
    case ShipState::DAMAGED:
        return TextStyle::RED;
    case ShipState::SUNKEN:
        return TextStyle::BLACK;
    default:
        return TextStyle::WHITE;
    }
}