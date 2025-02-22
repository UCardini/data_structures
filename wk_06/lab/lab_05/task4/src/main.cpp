#include "entertainmentCollection.h"
#include "exception.h"
#include "shelfContents.h"
#include <iostream>
#include <limits>

int mediaPrompt( bool );
movie* addMovie();
videoGame* addGame();

int main()
{
    entertainmentCollection<videoGame> gameShelf;
    entertainmentCollection<movie> movieShelf;
    int entry;
    while ( true )
    {
        bool isMovie = false;
        while ( true )
        {
            std::cout << "Would you like to view your (1=Movies or "
                         "2=Video Games): ";
            std::cin >> entry;
            std::cout << std::endl;
            if ( std::cin.fail() )
            { // this line is needed to make sure cin recieves an integer
                std::cin.clear();
                std::cin.ignore( std::numeric_limits<std::streamsize>::max(),
                                 '\n' );
                entry = -1;
                std::cerr << "[ERROR] - Invalid entry!" << std::endl;
            }
            else if ( entry == 1 || entry == 2 )
            {
                isMovie = entry == 1;
                break;
            }
        }
        int promptEntry;
        std::string entryType;
        promptEntry = mediaPrompt( isMovie );

        if ( promptEntry == 1 )
        {
            try
            {
                if ( isMovie )
                {
                    movie* p = addMovie();
                    movieShelf.shelfAdd( p );
                    p->printMovie();
                }
                else
                {
                    videoGame* p = addGame();
                    gameShelf.shelfAdd( p );
                    p->printGame();
                }
                std::cout << "\tAdded to Collection!" << std::endl;
            }
            catch ( fullShelf e )
            {
                if ( isMovie )
                {
                    entryType = "Movie";
                }
                else
                {
                    entryType = "Video Game";
                }
                std::cerr << "[Exception caught: " << e.msg << "]" << std::endl;
                std::cerr << entryType << " not added, remove a " << entryType
                          << " to add another to the shelf !" << std::endl;
            }
        }

        else if ( promptEntry == 2 )
        {
            try
            {
                if ( isMovie )
                {
                    movie* p = movieShelf.shelfRemove();
                    p->printMovie();
                    delete p;
                }
                else
                {
                    videoGame* p = gameShelf.shelfRemove();
                    p->printGame();
                    delete p;
                }
                std::cout << "\tRemoved from Collection!" << std::endl;
            }
            catch ( emptyShelf e )
            {
                if ( isMovie )
                    entryType = "Movie";
                else
                    entryType = "Video Game";
                std::cerr << "[Exception: " << e.msg << "]" << std::endl;
                std::cerr << "No " << entryType << "s left on shelf, add a "
                          << entryType << " before removing any more!"
                          << std::endl;
            }
        }
        else if ( promptEntry == 3 )
        {
            if ( isMovie )
            {
                int f = movieShelf.getIndex();
                std::cout << "\t\t[Movies currently in Collection: " << f << "]"
                          << std::endl;
            }
            else
            {

                int f = gameShelf.getIndex();
                std::cout << "\t\t[Video Games currently in Collection: " << f
                          << "]" << std::endl;
            }
        }
        else if ( promptEntry == 4 )
        {
            break;
        }
        else
            std::cerr << "[ERROR] - Invalid entry!" << std::endl;
    }
    return 0;
}

movie* addMovie()
{
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

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

    movie* p = new movie( title, description, ageRating ); // new operator

    return p;
}
int mediaPrompt( bool isMovie )
{

    int entry;
    std::string mediaType, spaces, beforeSpaces, afterSpaces;
    if ( isMovie )
    {
        mediaType    = "Movie";
        spaces       = "     ";
        beforeSpaces = "   ";
        afterSpaces  = "  ";
    }
    else
    {
        mediaType    = "Video Game";
        spaces       = "";
        beforeSpaces = "";
        afterSpaces  = "";
    }
    std::cout
        << "____________________________________________________________"
        << std::endl
        << "|[Press 1] - to add a " << mediaType << " to the shelf." << spaces
        << "               |" << std::endl
        << "|[Press 2] - to remove a " << mediaType << " from the shelf."
        << spaces << "          |" << std::endl
        << "|[Press 3] - to see how many " << mediaType << "s are on the shelf."
        << spaces << "   |" << std::endl
        << "|[Press 4] - to quit.                                        |"
        << std::endl
        << "|_____________________[" << beforeSpaces << mediaType << " Shelf"
        << afterSpaces << "]_____________________|" << std::endl;
    std::cout << "\t\tType your selection: ";
    std::cin >> entry;

    if ( std::cin.fail() )
    { // this line is needed to make sure cin recieves an integer
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        entry = -1;
    }
    std::cout << std::endl;
    return entry;
}

videoGame* addGame()
{
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    std::string name = "";
    std::cout << "Enter the Name: ";
    std::getline( std::cin, name );

    std::string genre = "";
    std::cout << "Enter the Genre: ";
    std::getline( std::cin, genre );

    std::string description = "";
    std::cout << "Enter the Description: ";
    std::cin >> description;
    std::getline( std::cin, description );

    videoGame* p = new videoGame( name, genre, description ); // new operator

    return p;
}
