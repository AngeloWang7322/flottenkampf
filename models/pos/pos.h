#pragma once
#ifndef POS_H
#define POS_H

class Pos
{
public:
    Pos();
    Pos(int, int);
    double distTo(Pos);
    Pos to(Pos);
    bool isOn(Pos);
    void multiply(double);
    void moveTowards(Pos, double = 1);
    double x;
    double y;
};
#endif