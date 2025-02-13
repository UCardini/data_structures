#pragma once
#include <iostream>

class wheel
{
private:
    int rangeMin;
    int rangeMax;

public:
    wheel( int rangeMin, int rangeMax )
    {
        this->rangeMin = rangeMin;
        this->rangeMax = rangeMax;
    };

    virtual int spin() // random int 1 - value
    {
        srand( time( 0 ) );
        int ball = rand() % ( rangeMax - rangeMin ) + 1;
        return ball;
    };

    void setRange( int rangeMin, int rangeMax )
    {
        this->rangeMin = rangeMin;
        this->rangeMax = rangeMax;
    }
};
