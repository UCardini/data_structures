#include "wheel.h"
class player
{
private:
    wheel rules;
    int money;

public:
    player(int);

    int spin();

    int getMoney();
    void modifyBalance(bool, int);
};
