#pragma once
#include <string>

class fullShelf
{
public:
    std::string msg;
    int maxMovies;

    fullShelf( std::string msg, int maxMovies)
    {
        this->msg       = msg;
        this->maxMovies = maxMovies;
    };
};

class emptyShelf
{
public:
    std::string msg;
    emptyShelf( std::string msg ) { this->msg = msg; };
};
