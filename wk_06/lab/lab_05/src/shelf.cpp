#include "shelf.h"
#include "exception.h"

shelf::shelf()
{
    // movies[ nextMovie ] = movie();
    nextMovie = 0;
};

void shelf::shelfAdd( movie movies )
{
    // Check the index
    if ( shelfSize <= nextMovie )
    {

        // std::cerr << "Exception FullShelf hit" << std::endl;
        throw fullShelf( "Shelf is full", this->movies, shelfSize, movies );
    }
    else
    {
        // std::cerr << "Exception not hit" << std::endl;
        this->movies[ nextMovie ] = movies;
        nextMovie++;
    }
}

movie shelf::shelfRemove()
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
