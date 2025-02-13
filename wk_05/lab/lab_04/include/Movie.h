#pragma once
#include "Show.h"

class Movie : protected Show
{
protected:
    string AgeRating;

public:
    void setAgeRating( string );

    string getAgeRating();

    void Play() override;
};
