#include "deck.h"
#include "exception.h"
#include <iostream>
#include <string>

/* So UH basically what happened is I didn't understand the idea of making a
 * "player deck" class with only half the deck I could have made this deck a
 * stack and generated the unique values like that! Might end up changing this
 * it's good that I made it though because I understand how to make a player
 * class better
 */
deck::deck()
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
        cardsLeft++;
        card* newCard = new card( suit, value );
        if ( head == nullptr )
        {
            head = newCard;
            tail = newCard;
        }
        else
        {
            tail->next = newCard;
            tail       = newCard;
        }
    }
};

deck::deck( deck* playerDeck )
{
    this->head      = playerDeck->head;
    this->tail      = playerDeck->tail;
    this->cardsLeft = 26;
};

deck::deck( card* newHead, card* newTail )
{
    this->head      = newHead;
    this->tail      = newTail;
    this->cardsLeft = 26;
}

void deck::printLeftInDeck() // Test cards are unique
{
    card* temp = head;
    while ( temp != nullptr )
    {
        std::cout << temp->face << std::endl; // print face value
        temp = temp->next;                    // iterate temp head...
    }
};

void deck::returnToDeck( card* inVal )
{
    cardsLeft++;
    this->tail->next = inVal;
    this->tail       = inVal;
};

card* deck::draw()
{
    if ( this->isEmpty() )
    {
        throw queueOverflow( "[EXCEPTION] - Queue Overflow!" );
    }

    card* temp = head;
    head       = head->next;
    temp->next = nullptr;
    cardsLeft--;
    return temp;
}

int deck::size()
{
    card* temp      = this->head;
    this->cardsLeft = 0;
    while ( temp != NULL )
    {
        this->cardsLeft++;

        temp = temp->next;
    }
    return this->cardsLeft;
}

deck* deck::split()
{
    card* temp = head;
    for ( int i = 0; i < 25; i++ )
    {
        temp = temp->next;
    }
    deck* created = new deck( temp->next, tail );
    tail          = temp;
    tail->next    = nullptr;
    return created;
}


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
