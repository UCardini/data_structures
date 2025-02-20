#include "shelf.h"
#include "movie.h"

shelf::shelf()
{
    index           = 1;
    movies[ index ] = movie();
};

void shelf::shelfAdd( movie movies )
{
    // Check the index
    if ( index <= 10 )
    {
        this->movies[ index ] = movies;
    }
    index++;
}
movie shelf::shelfRemove()
{
    index--;
    return movies[ index ];
}

int shelf::getIndex() { return index - 1; }
