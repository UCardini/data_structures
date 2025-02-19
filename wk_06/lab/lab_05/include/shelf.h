#pragma once
#include <iostream>

class shelf
{
private:
    movie movies[10];
    int index;

public:
    shelf()
    {
        index = 0;
        movies[index] = movie();
    };

    void shelfAdd(movie movies) { this->movies[index + 1] = movies; };
    movie shelfRemove(int)
    {
        index--;
        return movie();
    };
};
