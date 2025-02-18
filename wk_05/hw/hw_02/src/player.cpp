#include "player.h"
#include "wheel.h"

player::player(int money, wheel rules);
int player::createAndSpin(int rangeMax) { wheel(this->rangeMax = rangeMax); }
