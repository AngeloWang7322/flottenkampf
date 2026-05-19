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
    void add(Pos);
    bool isOn(Pos);
    void multiply(double);
    void moveTowards(Pos, double = 2);
    void clampToEdge();
    void randomize(double fac);
    double x;
    double y;
};
#endif