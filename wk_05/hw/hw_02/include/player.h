#include "wheel.h"
class player
{
private:
    wheel rules;
    int money;

public:
    player(int);

    int createAndSpin(int);

    int getMoney();
    void setMoney(int);
};
