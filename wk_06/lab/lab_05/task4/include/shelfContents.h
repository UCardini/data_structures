#pragma once
#include <iostream>
#include <string>

/* Class Name: movie
 * ****** Description ******
 * This Class creates a movie object thats stored in the shelf template and is
 composed of the things that the last lab decided would be good to know about a
 movie, frankly I'm not too concerned with the age rating of a movie when I pick
 it up but I digress. The contents of the movie object are the title description
 and... age rating these are set by a default constructor and a overloaded
 constructor and aren't changed by any functions. There is a function printMovie
 that displays the contents of the movie object to the console. We dont have
 getters and setters because we dont do anything other than look at the DVD box
 of the movie read the back and then the... age rating so we must keep in mind
 that we cannot change the title description or age rating and we cant do
 anything with the title description or... age rating either. We aren't
 cataloging the movies in and out and like storing the that so thats why we kept
 it simple.
 */
class movie
{
private:
    std::string title;
    std::string description;
    std::string ageRating;

public:
    // Default constructor
    movie()
    {
        title       = "";
        description = "";
        ageRating   = "";
    };

    // Overloaded constructor to create a movie
    movie( std::string title, std::string description, std::string ageRating )
    {
        this->title       = title;
        this->description = description;
        this->ageRating   = ageRating;
    };

    /*   Name: printMovie()
     *  Input: none
     * Output: none
     * ****** Description ******
     * This Function just display to the console the values contained in the
     * movie object, these are, title, description, and age rating.
     */
    void printMovie()
    {
        std::cout << "Title: " << title << " - Description: " << description
                  << ", For audiences: " << ageRating << std::endl;
    };
};

/* Class Name: videoGame
 * ****** Description ******
 * This Class creates a video game to be stored in a shelf I used things that I
 * would wanna know about a game that im just picking up for the first time as
 * the contents of the video game such as name, genre, and description we
 * construct a video game with our default which is never really used and our
 * Overloaded constructors, the default sets all the values to nothing as there
 * isn't any content in a game that is undefined (Obviously) the overloaded
 * constructor sets the name genre and description of the game. We only ever
 * remove or add the game to the shelf so there isn't any need for getters and
 * setters really we only need a print function to display the contents of the
 * object they're holding.
 */
class videoGame
{
private:
    std::string name;
    std::string genre;
    std::string description;

public:
    // Default constructor
    videoGame()
    {
        name        = "";
        genre       = "";
        description = "";
    };

    // Overloaded constructor to create a videoGame
    videoGame( std::string name, std::string genre, std::string description )
    {
        this->name        = name;
        this->genre       = genre;
        this->description = description;
    };

    /*   Name: printGame()
     *  Input: none
     * Output: none
     * ****** Description ******
     * This Function just display to the console the values contained in the
     * video game object, these are, name, genre, and description.
     */
    void printGame()
    {
        std::cout << "Video Game: " << name << ", Genre: " << genre
                  << ", Description: " << description << std::endl;
    };
};
