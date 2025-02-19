#include "movie.h"
#include "shelf.h"
#include <iostream>

int main()
{
    while (true)
    {
        shelf s;
        movie p = s.shelfRemove();
        int entry;
        while (true)
        {
            std::cout
                << "Press 1 to add a movie to the shelf." << std::endl
                << "Press 2 to remove a movie from the shelf." << std::endl
                << "Press 3 to see how many movies are currently on the shelf."
                << std::endl
                << "Press 4 to quit." << std::endl;
            std::cin >> entry;
            if (entry == 1)
            {
                break;
            }
            else if (entry == 2)
            {
                break;
            }
            else if (entry == 3)
            {
                break;
            }
            else if (entry == 4)
            {
                break;
            }
            else
                std::cout << "[ERROR] - Invalid entry!" << std::endl;
        }
    }

    //
    return 0;
}
