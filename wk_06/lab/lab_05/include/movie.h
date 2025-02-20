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

    std::string getTitle() { return title; };
    void setTitle( std::string title ) { this->title = title; }

    std::string getDescription() { return description; };
    void setDescription( std::string description )
    {
        this->description = description;
    };

    std::string getAgeRating() { return ageRating; };
    void setAgeRating( std::string ageRating ) { this->ageRating = ageRating; };

    void printMovie()
    {
        std::cout << "Title: " << title << " - Description: " << description
                  << ", For audiences: " << ageRating << std::endl;
    }
};
