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

class player
{
public:
    deck hand;
    player(deck);
};
