#pragma once
#include "movie.h"

class shelf
{
public:
    static const int shelfSize = 1;
    movie movies[ shelfSize ];
    int nextMovie;

    shelf();

    void shelfAdd( movie );
    movie shelfRemove();
    int getIndex();
};
