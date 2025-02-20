#pragma once
#include "movie.h"
#include <iostream>

class shelf
{
private:
    movie movies[ 10 ];
    int index;

public:
    shelf();

    void shelfAdd( movie );
    movie shelfRemove();
    int getIndex();
};
