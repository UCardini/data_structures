#include "movie.h"
#include "shelf.h"
#include <iostream>
#include <limits>

int main()
{
    shelf s;
    int entry;
    while (true)
    {
        std::cout
            << " ____________________________________________________________"
            << std::endl
            << "|[Press 1] - to add a movie to the shelf.                    |"
            << std::endl
            << "|[Press 2] - to remove a movie from the shelf.               |"
            << std::endl
            << "|[Press 3] - to see how many movies are on the shelf.        |"
            << std::endl
            << "|[Press 4] - to quit.                                        |"
            << std::endl
            << "|____________________________________________________________|"
            << std::endl;
        std::cout << "\t\tType your selection: ";
        std::cin >> entry;
        std::cout << std::endl;
        if (entry == 1)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string title = "";
            std::cout << "Enter the Title: ";
            std::getline(std::cin, title);

            std::string description = "";
            std::cout << "Enter the Description: ";
            std::getline(std::cin, description);

            std::string ageRating = "";
            std::cout << "Enter the Age Rating: ";
            std::cin >> ageRating;
            std::cout << std::endl;

            movie p(title, description, ageRating);
            s.shelfAdd(p);
            std::cout << "\t\t[Added to Collection]" << std::endl;
            p.printMovie();
        }
        else if (entry == 2)
        {
            movie p = s.shelfRemove();
            std::cout << "\t\t[Removed from Collection]" << std::endl;
            p.printMovie();
        }
        else if (entry == 3)
        {
            int f = s.getIndex();
            std::cout << "\t\t[Movies currently in Collection: " << f << "]"
                      << std::endl;
        }
        else if (entry == 4)
        {
            break;
        }
        else
            std::cout << "[ERROR] - Invalid entry!" << std::endl;
    }

    //
    return 0;
}
