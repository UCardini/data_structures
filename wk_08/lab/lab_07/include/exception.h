#pragma once
#include <string>
class underMinSize
{
public:
    std::string msg;

    underMinSize( std::string msg ) { this->msg = msg; };
};

class nullPrevious
{
public:
    std::string msg;

    nullPrevious( std::string msg ) { this->msg = msg; };
};
class nullNext
{
public:
    std::string msg;

    nullNext( std::string msg ) { this->msg = msg; };
};

class overMaxSize
{
public:
    std::string msg;

    overMaxSize( std::string msg ) { this->msg = msg; };
};
