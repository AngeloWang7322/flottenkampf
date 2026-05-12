#ifndef UTILS_H
#define UTILS_H
#include <string>

using namespace std;

class Utils
{
public:
    static string colorize(string, TextStyle);
    static char readInput();
};
#endif