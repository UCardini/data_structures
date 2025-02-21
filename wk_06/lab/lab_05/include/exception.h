#pragma once
#include "movie.h"
#include <string>

class fullShelf
{
public:
    std::string msg;
    int maxMovies;
    movie* overFlow;

    fullShelf( std::string msg, int maxMovies, movie* overFlow )
    {
        this->msg       = msg;
        this->maxMovies = maxMovies;
        this->overFlow  = overFlow;
    };
};

class emptyShelf
{
public:
    std::string msg;
    emptyShelf( std::string msg ) { this->msg = msg; };
};
