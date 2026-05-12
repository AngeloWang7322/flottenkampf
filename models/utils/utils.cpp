#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "../types.h"
#include "utils.h"

string Utils::colorize(string str, TextStyle style)
{
    string code;
    switch (style)
    {
    case TextStyle::RED:
        code = "\e[0;31m";
    case TextStyle::YELLOW:
        code = "\e[0;33m";
    }
    return code + str + "\033[0m";
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
