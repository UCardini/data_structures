#include "wheel.h"
class player
{
private:
    wheel rules;
    int money;

public:
    player( int money = 1000 );

    int spinWheel();
    int getMoney();
    void setMoney( int );
};
