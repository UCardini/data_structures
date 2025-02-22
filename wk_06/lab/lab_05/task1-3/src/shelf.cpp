#include "shelf.h"
#include "exception.h"

shelf::shelf()
{
    // movies[ nextMovie ] = movie();
    nextMovie = 0; // Starts empty
};
/*  The shelf add method was created following the constraints of a stack
 *  this means that first into the stack is the last out of it and so need
 *  to make sure that the size never exceeds the limit of our stack and when
 *  it does it throws an exception and gives an explaination on what the 
 *  available options are they can use.
 *  Essentially if the size of the stack is under our global constant for 
 *  size it will add an element into the stack and if it goes over it throws
 *  an exception.
 *  The same is true of the shelf remove method except it checks if the stack 
 *  contains anything. If the contents of the shelf stack are empty then throw
 *  an exception otherwise it decrements the stacks size and returns the movie.
 */
void shelf::shelfAdd( movie* movies )
{
    // Check the index
    if ( shelfSize <= nextMovie )
    {

        // std::cerr << "Exception FullShelf hit" << std::endl;
        delete movies;
        throw fullShelf( "Shelf is full", shelfSize  );
    }
    else
    {
        // std::cerr << "Exception not hit" << std::endl;
        this->movies[ nextMovie ] = movies;
        nextMovie++;
    }
}

movie* shelf::shelfRemove()
{
    if ( nextMovie <= 0 )
    {
        // std::cerr << "Exception EmptyShelf hit" << std::endl;
        throw emptyShelf( "Shelf is empty" );
    }
    else
    {
        // std::cerr << "Exception not hit" << std::endl;
        nextMovie--;
        return movies[ nextMovie ];
    }
}

int shelf::getIndex() { return nextMovie; }
