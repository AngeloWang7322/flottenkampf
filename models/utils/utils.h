#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
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

    template <typename T>
    static bool includes(const T& needle, const vector<T>& haystack);
};
#endif