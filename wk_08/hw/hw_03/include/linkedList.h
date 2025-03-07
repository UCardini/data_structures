#pragma once
#include <string>

class card // nodes for deck class
{
public:
    int suit;         // Required
    int value;        // Required
    std::string face; // Not Required
    card* next;       // Required

    card( int, int );
};

class deck // create player class that inherits deck class
           // can draw cards and has its own hand that it draws
           // from the deck class and can return to the deck class
{
private:
    int cardsLeft; // Not sure if required
    card* tail;
    card* head;

public:
    deck();

    void printLeftInDeck();
    bool isEmpty();
    bool isFull();
    void returnToDeck( card* );
    card peek();
    int size();
    card* draw();
};
