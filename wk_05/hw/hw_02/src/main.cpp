#include "player.h"

int main()
{
    srand(time(0));
    int boardRange = 0;
    while (true)
    {
        std::cout << "Welcome to the electronic Roulette wheel type of game!"
                  << std::endl;
        std::cout
            << "Start by selecting how many numbers are on the table (select "
               "a number 6 - 20): ";

        std::cin >> boardRange;
        std::cout << std::endl;

        if (boardRange < 6 || 20 < boardRange)
        {
            std::cout << "[ERROR] - The value you entered is invalid!"
                      << std::endl;
            std::cout
                << "please enter a value "
                   "greater than or equal to 6 and less than or equal to 20"
                << std::endl;
        }
        else
            break;
    }
    player p(boardRange);

    while (true)
    {
        bool choice;
        if (p.getMoney() == 0)
        {
            std::cout << "Unforunately you ran out of money! " << std::endl;
            std::cout << "Thanks for playing!" << std::endl;
            break;
        }
        while (true)
        {
            int selection = 0;

            std::cout << "Would you like to make a bet (1 = yes, 0 to quit): ";
            std::cin >> selection;
            std::cout << std::endl;
            if (1 < selection || selection < 0)
            {
                std::cout << "[ERROR] - The value you entered is invalid!"
                          << std::endl;
            }
            else
            {
                choice = selection;
                break;
            }
        }
        if (!choice)
        {
            std::cout << "Remaining Balance: " << p.getMoney() << std::endl;
            std::cout << "Thanks for playing!" << std::endl;
            break;
        }

        int playerBet = 0;
        while (true)
        {
            std::cout << "Current Balance: $" << p.getMoney() << std::endl;
            std::cout
                << "Enter the bet you would like to make (Note: bet cannot "
                   "exceed balance): $";
            std::cin >> playerBet;
            if (playerBet <= 0 || p.getMoney() < playerBet)
            {
                std::cout
                    << "Please enter a value greater than zero or less than "
                       "equal to you current balance!"
                    << std::endl
                    << std::endl;
            }
            else
                break;
        }

        int ball = p.spin();
        int betModify = 0;
        bool win = false;
        while (true)
        {
            if (p.getMoney() - playerBet < playerBet)
            {
                std::cout << "You landed on " << ball
                          << ". Would you like to [1]keep your bet or [2]halve "
                             "your bet ";
            }
            else
            {
                std::cout << "You landed on " << ball
                          << ". Would you like to [1]keep your bet, [2]halve "
                             "your bet "
                             "or [3]double your bet?: ";
            }
            std::cin >> betModify;
            std::cout << std::endl;

            if (betModify == 1)
            {
                // house gets 1 spin to try and beat your number
                win = p.spin() < ball;
                p.modifyBalance(win, playerBet);
                break;
            }
            else if (betModify == 2)
            {
                playerBet /= 2;
                // house gets 2 spins to try and beat your number
                //  both have to beat your number to win
                win = p.spin() < ball || p.spin() < ball;
                p.modifyBalance(win, playerBet);
                break;
            }
            else if (betModify == 3)
            {
                if (p.getMoney() - playerBet < playerBet)
                {
                    win = p.spin() < ball && p.spin() < ball;
                    p.modifyBalance(win, playerBet);
                    break;
                }
                else
                {
                    playerBet *= 2;
                    // house gets 2 spins to try and beat your number
                    // only 1 needs to beat yours to win
                    win = p.spin() < ball && p.spin() < ball;
                    p.modifyBalance(win, playerBet);
                    break;
                }
            }
            else
            {
                std::cout << "[ERROR] - The value you entered is invalid!"
                          << std::endl;
            }
        }
        if (win)
            std::cout << "Congradulations you won: $" << playerBet;
        else
            std::cout << "Unforunately you lost: $" << playerBet;
        std::cout << "! Your remaining balance is: $" << p.getMoney()
                  << std::endl;
    }
    return 0;
}
