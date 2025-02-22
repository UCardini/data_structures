#pragma once
#include <iostream>
#include <string>

class movie
{
public:
    std::string title;
    std::string description;
    std::string ageRating;

    movie()
    {
        title       = "";
        description = "";
        ageRating   = "";
    };

    movie( std::string title, std::string description, std::string ageRating )
    {
        this->title       = title;
        this->description = description;
        this->ageRating   = ageRating;
    };

    void printMovie()
    {
        std::cout << "Title: " << title << " - Description: " << description
                  << ", For audiences: " << ageRating << std::endl;
    }
};
