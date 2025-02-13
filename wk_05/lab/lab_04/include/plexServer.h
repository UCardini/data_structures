#pragma once
#include <iostream>
#include <string>
class plexServer
{
private:
    std::string title;
    std::string description;

public:
    plexServer(); // default constructor
    plexServer(std::string, std::string);
    virtual void play();
    void Details();

    // getters
    std::string getTitle();
    std::string getDescription();

    // setters
    void setTitle(std::string);
    void setDescription(std::string);
};
