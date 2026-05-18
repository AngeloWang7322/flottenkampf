#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
#include "../types.h"

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

    template <typename T>
    static bool includes(const T &needle, const vector<T> &haystack);
};
#endif