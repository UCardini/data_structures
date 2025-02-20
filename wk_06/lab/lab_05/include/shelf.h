#pragma once
#include "movie.h"

class shelf
{
private:
    movie movies[ 2 ];
    int nextMovie;

public:
    shelf();

    void shelfAdd( movie );
    movie shelfRemove();
    int getIndex();
};
