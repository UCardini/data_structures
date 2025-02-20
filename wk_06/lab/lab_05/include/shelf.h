#pragma once
#include "movie.h"

class shelf
{
private:
    movie movies[ 2 ];
    int nextMovie;

public:
    static const int shelfSize = 1;
    shelf();

    void shelfAdd( movie );
    movie shelfRemove();
    int getIndex();
};
