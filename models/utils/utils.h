#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
#include "../types.h"
#include "../pos/pos.h"

using namespace std;

class Utils
{
public:
    static string colorize(string, TextStyle);
    static char readInput();
    static bool isInputA(char);
    static bool isInputB(char);
    static Action parseInputA(char);
    static Action parseInputB(char);
    static TextStyle shipStateToColor(ShipState);
    static Pos snapToBoarder();

    template <typename T>
    static bool includes(const T &needle, const vector<T> &haystack);
};
#endif