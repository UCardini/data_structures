#pragma once
#include <string>

class stackOverflow
{
public:
    stackOverflow( std::string msg ) { this->msg = msg; };
    std::string msg;
};

class stackUnderflow
{
public:
    stackUnderflow( std::string msg ) { this->msg = msg; };
    std::string msg;
};

class queueOverflow
{
public:
    queueOverflow( std::string msg ) { this->msg = msg; };
    std::string msg;
};

class queueUnderflow
{
public:
    queueUnderflow( std::string msg ) { this->msg = msg; };
    std::string msg;
};
