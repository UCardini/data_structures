#pragma once
#include "linkedList.h"
#include "exception.h"
#include <iostream>
#include <string>

// constructor fills suit and value
// also fills the string face value of the card
// just so it looks nice.
card::card( int suit, int value )
{
    this->next = nullptr;

    switch ( value )
    {
    case 1:
        this->value = 1;
        this->face  = "Ace";
        break;
    case 2:
        this->value = 2;
        this->face  = "Deuce";
        break;
    case 3:
        this->value = 3;
        this->face  = "Three";
        break;
    case 4:
        this->value = 4;
        this->face  = "Four";
        break;
    case 5:
        this->value = 5;
        this->face  = "Five";
        break;
    case 6:
        this->value = 6;
        this->face  = "Six";
        break;
    case 7:
        this->value = 7;
        this->face  = "Seven";
        break;
    case 8:
        this->value = 8;
        this->face  = "Eight";
        break;
    case 9:
        this->value = 9;
        this->face  = "Nine";
        break;
    case 10:
        this->value = 10;
        this->face  = "Ten";
        break;
    case 11:
        this->value = 11;
        this->face  = "Jack";
        break;
    case 12:
        this->value = 12;
        this->face  = "Queen";
        break;
    case 13:
        this->value = 13;
        this->face  = "King";
        break;
    }

    this->face += " of ";

    switch ( suit )
    {
    case 1:
        this->suit = 1;
        this->face += "Hearts";
        break;
    case 2:
        this->suit = 2;
        this->face += "Diamonds";
        break;
    case 3:
        this->suit = 3;
        this->face += "Spades";
        break;
    case 4:
        this->suit = 4;
        this->face += "Clubs";
        break;
    }
}
/* Works like a queue but using linked list
 * have a head and a tail tracked inside this
 * class instead of just the head for a linked
 * list, not sure if this is required to make
 * it work just yet I only included it just in
 * case we do! */
// needs broken up into simpler parts for readability
// Ideally a function to check for uniquiness could do this
// to make the initialization simpler because It's a little confusing right
// now
deck::deck() // when we construct our deck we need it to contain 52 random non
             // repeating "cards"
{
    head      = nullptr;
    cardsLeft = 0;
    srand( time( 0 ) );
    for ( int i = 0; i < 52; i++ )
    {
        int suit, value;
        bool isUnique;

        while ( true )
        {
            isUnique = true; // first card is unique
            suit     = rand() % 4 + 1;
            value    = rand() % 13 + 1;

            // check if the card already in the deck
            //  set isUnique to false it is
            card* temp = head;
            while ( temp != nullptr )
            {
                if ( temp->suit == suit && temp->value == value )
                {
                    isUnique = false; // card isn't unique
                    break;
                }
                temp = temp->next;
            }

            if ( isUnique )
                break; // break when unique
        }

        // add the unique card to the deck
        cardsLeft++;
        // std::cout << cardsLeft << std::endl;
        card* newCard = new card( suit, value );
        if ( head == nullptr )
        {
            // if the deck is empty, set both head and tail to the new card
            head = newCard;
            tail = newCard;
        }
        else
        {
            // next card is at the end of the list
            tail->next = newCard;
            tail       = newCard;
        }
    }
};

void deck::printLeftInDeck() // Test cards are unique
{
    // Temporary for testing
    card* temp = head;
    while ( temp != nullptr )
    {
        std::cout << temp->face << std::endl; // print face value
        temp = temp->next;                    // iterate temp head...
    }
};

bool deck::isEmpty()
{ //
    return cardsLeft == 0;
};

bool deck::isFull()
{ //
    return cardsLeft == 52;
};

<<<<<<< HEAD
void deck::returnToDeck( card ) // Needs implemented
    {

    };

card deck::peek() // Needs implemented
=======
void deck::returnToDeck( card inVal )
>>>>>>> bf0260dbb9b2ebd47269d57f87a0ccd458baec4b
{
    cardsLeft++;
    this->tail->next = &inVal; 
    this->tail       = &inVal;
};

card deck::peek()
{ //
    return *tail;
};

int deck::size()
{ //
    return cardsLeft;
};

card deck::draw() // needs to be card type
// change to regular card
{
    if ( this->isEmpty() )
    {
        throw queueOverflow( "[EXCEPTION] - Queue Overflow!" );
    }

    card temp = card( head->suit, head->value ); 
    delete head;
    head       = head->next;
    cardsLeft--;
    return temp;
};
