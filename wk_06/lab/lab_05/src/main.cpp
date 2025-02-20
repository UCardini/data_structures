#include "exception.h"
#include "movie.h"
#include "shelf.h"
#include <iostream>
#include <limits>

int main()
{
    shelf s;
    int entry;
    while ( true )
    {
        std::cout << " ____________________________________________________"
                     "________"
                  << std::endl
                  << "|[Press 1] - to add a movie to the shelf.            "
                     "        |"
                  << std::endl
                  << "|[Press 2] - to remove a movie from the shelf.       "
                     "        |"
                  << std::endl
                  << "|[Press 3] - to see how many movies are on the "
                     "shelf.        |"
                  << std::endl
                  << "|[Press 4] - to quit.                                "
                     "        |"
                  << std::endl
                  << "|____________________________________________________"
                     "________|"
                  << std::endl;
        std::cout << "\t\tType your selection: ";
        std::cin >> entry;
        if ( std::cin.fail() )
        {
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(),
                             '\n' );
            entry = -1;
        }
        std::cout << std::endl;
        if ( entry == 1 )
        {
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(),
                             '\n' );

            std::string title = "";
            std::cout << "Enter the Title: ";
            std::getline( std::cin, title );

            std::string description = "";
            std::cout << "Enter the Description: ";
            std::getline( std::cin, description );

            std::string ageRating = "";
            std::cout << "Enter the Age Rating: ";
            std::cin >> ageRating;
            std::cout << std::endl;

            movie p( title, description, ageRating );
            try
            {
                s.shelfAdd( p );
                std::cout << "\tAdded to Collection!" << std::endl;
                p.printMovie();
            }
            catch ( fullShelf e )
            {
                std::cerr << "[Exception caught: " << e.msg << "] - ";
                std::cerr
                    << title
                    << " not added, remove a movie to add another to shelf!"

                    << std::endl;
            }
        }

        else if ( entry == 2 )
        {
            try
            {
                movie p = s.shelfRemove();
                std::cout << "\tRemoved from Collection!" << std::endl;
                p.printMovie();
            }
            catch ( emptyShelf e )
            {
                std::cerr << "[Exception: " << e.msg << "]" << std::endl;
                std::cerr
                    << "No movies left on shelf, add a movie before removing "
                       "any more!"
                    << std::endl;
            }
        }
        else if ( entry == 3 )
        {
            int f = s.getIndex();
            std::cout << "\t\t[Movies currently in Collection: " << f << "]"
                      << std::endl;
        }
        else if ( entry == 4 )
        {
            break;
        }
        else
            std::cout << "[ERROR] - Invalid entry!" << std::endl;
    }
    return 0;
}
