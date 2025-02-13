#pragma once
#include "plexServer.h"
#include <iostream>
#include <string>
class show : plexServer
{
private:
    std::string title;
    std::string description;

public:
    // getters
    std::string getTitle();
    std::string getDescription();
    // setters
    void setTitle();
    void setDescription();
};

class showContent : show
{
private:
    int season;
    int episode;
    std::string summary;

public:
    showContent();
    showContent(int, int, std::string);
    void play();

    // getters
    int getSeason();
    int getEpisode();
    std::string getSummary();

    // setters
    void setSeason(int);
    void setEpisode(int);
    void setSummary(std::string);
};

class movie : show
{
private:
    std::string title;
    std::string description;
    double rating;

public:
    movie();
    movie(std::string, std::string, double);

    // getters
    std::string getTitle();
    std::string getDescription();
    double getRating();

    // setters
    void setTitle(std::string);
    void setDescription(std::string);
    void setRating(double);
};
