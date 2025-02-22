#pragma once
#include <iostream>
#include <string>

class movie
{
private:
    std::string title;
    std::string description;
    std::string ageRating;

public:
    movie()
    { // Default constructor
        title       = "";
        description = "";
        ageRating   = "";
    };

    movie( std::string title, std::string description, std::string ageRating )
    { // Overloaded constructor to create a movie
        this->title       = title;
        this->description = description;
        this->ageRating   = ageRating;
    };

    void printMovie()
    { // Displays movie to console
        std::cout << "Title: " << title << " - Description: " << description
                  << ", For audiences: " << ageRating << std::endl;
    };
};

class videoGame
{
private:
    std::string name;
    std::string genre;
    std::string description;

public:
    videoGame()
    { // Default constructor
        name        = "";
        genre       = "";
        description = "";
    };

    videoGame( std::string name, std::string genre, std::string description )
    { // Overloaded constructor to create a movie
        this->name        = name;
        this->genre       = genre;
        this->description = description;
    };

    void printGame()
    { // Displays Video Game to console
        std::cout << "Video Game: " << name << ", Genre: " << genre
                  << ", Description: " << description << std::endl;
    };
};
