#include "player.h"

int main()
{
    int playerBalance = 1000;
    std::cout << "Welcome to the electronic Roulette wheel type of game!"
              << std::endl;
    while (true)
    {
        std::string choice = "";
        std::cout
            << "Would you like to make a bet (1 = yes), anything else for no: ";
        std::cin >> choice;
        bool cont = choice != "1";
        if (playerBalance == 0 || cont)
        {
            std::cout << "Remaining Balance: " << playerBalance;
            std::cout << "Thanks for playing!";
            break;
        }
    }
    return 0;
}
