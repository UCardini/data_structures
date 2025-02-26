#include "entertainmentCollection.h"
#include "exception.h"
#include "shelfContents.h"
#include <iostream>
#include <limits> // cin freaks out when invalid data types are used for the variable thats assigned

// Function prototypes
int mediaPrompt( bool );
movie* addMovie();
videoGame* addGame();

int main()
{
    // Creating our respective shelves, not sure if using both is required
    entertainmentCollection<videoGame> gameShelf;
    entertainmentCollection<movie> movieShelf;

    while ( true ) // Main loop breaks when 4 is entered in mediaPrompt()
    {
        bool isMovie = false;
        /* User enters 1 to access the movies shelf and 2 to access
         * video games shelf
         * Loop to filter out bad entrys breaks when it accepts an entry
         */
        while ( true )
        {
            int entry = 0;
            std::cout << "Would you like to view your (1=Movies or "
                         "2=Video Games): ";
            std::cin >> entry;
            std::cout << std::endl;

            // this line is needed to make sure cin recieves an integer
            // if it does it breaks the while loop
            if ( std::cin.fail() )
            {
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
        std::string entryType;

        /*prompt changes for movie and video game we pass a boolean "isMovie"
         * which is isMovie == true outputs the prompt for the movie shelf to
         * the user
         */
        int promptEntry = mediaPrompt( isMovie );

        if ( promptEntry == 1 )
        {
            try // Try creating creating and adding movie or game
            {
                if ( isMovie )
                {
                    movie* p = addMovie();
                    movieShelf.shelfAdd( p );
                    p->printMovie(); // Displays current movie could be memory
                                     // leak might need to delete p after this
                }
                else
                {
                    videoGame* p = addGame();
                    gameShelf.shelfAdd( p );
                    p->printGame();
                }
                std::cout << "\tAdded to Collection!" << std::endl;
            }
            catch ( fullShelf e ) // Displays error msg from shelfcontents
            {
                if ( isMovie )
                {
                    entryType = "Movie";
                }
                else
                {
                    entryType = "Video Game";
                }
                /* std::cerr standard error output? Is this seriously used
                 * as SOP for programmers, as far as I know it's the same as
                 * std::cout why use this?
                 */
                std::cerr << "[Exception caught: " << e.msg << "]" << std::endl;
                std::cerr << entryType << " not added, remove a " << entryType
                          << " to add another to the shelf !" << std::endl;
            }
        }

        else if ( promptEntry == 2 )
        {
            /* I know to delete the ptr here because the ptr is gonna stop being
             * accessed and the stack decremented we only create more ptrs and
             * dont reassign anything so here is a memory leak if we dont remove
             * the ptr
             */
            try // Try to remove a movie/video game
            {
                if ( isMovie )
                {
                    movie* p = movieShelf.shelfRemove();
                    p->printMovie();
                    delete p; // Delete to stop obvious mem leak
                }
                else
                {
                    videoGame* p = gameShelf.shelfRemove();
                    p->printGame();
                    delete p; // Delete to stop obvious mem leak
                }
                std::cout << "\tRemoved from Collection!" << std::endl;
            }
            catch ( emptyShelf e ) // Shelf size <= 0!
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
                int f = movieShelf.getIndex(); // pulling the stack location
                std::cout << "\t\t[Movies currently in Collection: " << f << "]"
                          << std::endl;
            }
            else
            {
                int f = gameShelf.getIndex(); // pulling the stack location
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

/*   Name: addMovie()
 *  Input: none
 * Output: movie ptr
 * ****** Description ******
 * This Function creates movie objects
 * to be put into "Entertainment Collection",
 * through prompting the user it gathers relevant
 * information to create a movie and generates one.
 */
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

/*   Name: addGame()
 *  Input: None
 * Output: videoGame ptr
 * ****** Description ******
 * This Function creates video game objects
 * to be put into "Entertainment Collection",
 * through prompting the user it gathers relevant
 * information to create a videoGame and generates
 * one.
 */
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

/*   Name: mediaPrompt()
 *  Input: isMovie
 * Output: Users Input
 * ****** Description ******
 * This Function is used to prompt the user
 * for what they want to do in their repective
 * (videoGame or movie) shelves. It takes isMovie
 * as an input to display the relevant prompts
 * and captures and outputs the users selection.
 */
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
        << "_____________________________________________________________"
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
