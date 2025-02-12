#pragma once
#include <iostream>
#include <string>

class wheel
{
private:
    int maxValue;

public:
    wheel(int maxValue) { this->maxValue = maxValue; };

    int spin() // random int 1 - value
    {
        int ball = rand() % maxValue + 1;
        return ball;
    };
};
