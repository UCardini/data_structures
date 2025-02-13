#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Show
{
protected:
    string Title;
    string Description;

public:
    Show();
    Show( string, string );

    void setTitle( string );
    void setDescription( string );

    string getTitle();
    string getDescription();

    virtual void Play() = 0;
    void Details();
};
