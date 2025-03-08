#pragma once
#include "deck.h"
class sidePile
{
private:
    const static int size = 5;
    card* stack[ size ];
    int top;

public:
    sidePile();
    std::string display( card* );
    void push( card* );
    card* pop();
    int remaining();
};

// Needs to initialize to a split deck from the deck class
// 26 cards needs functionality like our deck class
class player
{
private:
public:
};
