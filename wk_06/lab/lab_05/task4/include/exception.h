#pragma once
#include <string>

class fullShelf
{
public:
    std::string msg;
    int maxItems;

    fullShelf( std::string msg, int maxItems )
    {
        this->msg      = msg;
        this->maxItems = maxItems;
    };
};

class emptyShelf
{
public:
    std::string msg;
    emptyShelf( std::string msg ) { this->msg = msg; };
};
