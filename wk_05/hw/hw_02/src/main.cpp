#include "../include/player.h"
#include "../include/wheel.h"

int main()
{
    srand(time(0));
    wheel roulett(25);
    std::cout << roulett.spin() << std::endl;
    return 0;
}
