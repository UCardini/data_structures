#include "player.h"
#include "wheel.h"

player::player(int rangeMax)
{
    money = 1000;
    rules = wheel(rangeMax);
};

int player::createAndSpin(int rangeMax)
{
    wheel rules(rangeMax);
    this->rules = rules;

    int ballValue = rules.spin();
    return ballValue;
}

int player::getMoney() { return money; }
void player::setMoney(int money) { this->money = money; }
