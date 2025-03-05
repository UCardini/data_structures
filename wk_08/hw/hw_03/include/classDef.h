#pragma once
#include <ctime>
#include <string>

class card // nodes for deck class
{
public:
    int suit;
    int value;
    std::string face;
    card* next;

    card( int suit, int value )
    {
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

        this->next = nullptr;
    };
};

class deck // operates similarly to a queue
{          // player draws a card from the
private:
    int cardsLeft;
    card* tail;
    card* head;

public:
    deck() // when we construct our deck we need it to contain 52 random non
           // repeating "cards"
    {
        if ( head == nullptr )
        {
            head = new card( rand() % 4 + 1, rand() % 13 + 1 );
        }
        srand( time( 0 ) );
        card* temp = head;
        for ( int i = 0; i < 52; i++ )
        {
            int suit  = rand() % 4 + 1;
            int value = rand() % 13 + 1;
            while ( temp != nullptr )
            {

                temp = temp->next;
            }
        }
    };
    bool isEmpty();
    bool isFull();
    void returnToDeck( card );
    // card draw();
    card peek();
    int size();
    // void empty();

    card draw()
    {
        if ( this->isEmpty() )
        {
            // throw queueOverflow()
        }
        card* temp = head;
        head       = head->next;

        if ( head == nullptr )
        {
            tail = nullptr;
        }
        return *temp; // mem leak
    }
};

class sidePile // my stack
{
private:
    card top;

public:
};
