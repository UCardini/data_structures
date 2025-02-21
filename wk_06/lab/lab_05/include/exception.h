#pragma once
#include "movie.h"
#include <string>

class fullShelf
{
public:
    std::string msg;
    int maxMovies;
    movie* onShelf;
    movie overFlow;

    fullShelf( std::string msg, movie* onShelf, int maxMovies, movie overFlow )
    {
        this->msg       = msg;
        this->maxMovies = maxMovies;
        this->onShelf   = onShelf;
        this->overFlow  = overFlow;
    };
};

class emptyShelf
{
public:
    std::string msg;
    emptyShelf( std::string msg ) { this->msg = msg; };
};

