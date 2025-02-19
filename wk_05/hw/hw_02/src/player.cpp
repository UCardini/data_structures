#include "player.h"
#include "wheel.h"

player::player(int rangeMax)
{
    money = 1000;
    rules = wheel(rangeMax);
};

int player::spin() { return rules.spin(); }

int player::getMoney() { return money; }
void player::modifyBalance(bool win, int money)
{
    if (win)
        this->money += money;
    else
        this->money -= money;
}
