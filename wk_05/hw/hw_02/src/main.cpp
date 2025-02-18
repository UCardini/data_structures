#include "player.h"

int main()
{
    int boardRange = 0;
    std::cout << "Welcome to the electronic Roulette wheel type of game!"
              << std::endl;
    std::cout << "Start by selecting how many numbers are on the table (select "
                 "a number 6 - 20): ";
    std::cin >> boardRange;
    std::cout << std::endl;

    player p(boardRange);

    while (true)
    {
        bool choice;
        std::cout << "Would you like to make a bet (1 = yes, 0 to quit): ";
        std::cin >> choice;
        if (p.getMoney() == 0 || choice)
        {
            std::cout << "Remaining Balance: " << p.getMoney() << std::endl;
            std::cout << "Thanks for playing!";
            break;
        }
        std::cout << "Current Balance: $" << p.getMoney() << std::endl;
        std::cout << "Enter the bet you would like to make (Note: bet cannot "
                     "exceed balance): ";
        int playerBet = 0;
        std::cin >> playerBet;
        if (playerBet < 0 || p.getMoney() < playerBet)
        {
            std::cout << "Please enter a value greater than zero or less than "
                         "equal to you current balance!"
                      << std::endl
                      << std::endl;
            break;
        }
    }
    return 0;
}
