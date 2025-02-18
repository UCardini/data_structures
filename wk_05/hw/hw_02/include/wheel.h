#pragma once
#include <iostream>

class wheel
{
private:
    int rangeMax;

public:
    wheel() { rangeMax = 10; }
    wheel(int rangeMax) { this->rangeMax = rangeMax; };

    virtual int spin() // random int 1 - value
    {
        srand(time(0));
        int ball = rand() % (rangeMax) + 1;
        return ball;
    };

    void setRange(int rangeMax) { this->rangeMax = rangeMax; }
};
