#include "wheel.h"
class player
{
private:
    wheel rules;
    int money;

public:
    player(int, wheel);

    int createAndSpin(int);
};
