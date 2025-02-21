#pragma once
#include "movie.h"

class shelf
{
public:
    static const int shelfSize = 1; // hard limit for the shelf size...
    movie* movies[ shelfSize ];     
    int nextMovie;

    shelf(); // Default constructor

    void shelfAdd( movie* );
    movie* shelfRemove();
    int getIndex();
};
