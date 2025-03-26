#pragma once
#include <string>
class queueOverflow
{
public:
    std::string msg;

    queueOverflow( std::string msg ) { this->msg = msg; };
};

class stackOverflow
{
public:
    std::string msg;

    stackOverflow( std::string msg ) { this->msg = msg; };
};
class stackUnderflow
{
public:
    std::string msg;

    stackUnderflow( std::string msg ) { this->msg = msg; };
};
