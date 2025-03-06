#pragma once
#include <ctime>
#include <iostream>
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
        head = nullptr;
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
                tail       = newCard; // updates tail
            }
        }

        /*// Test cards are unique
        card* temp = head;
        while ( temp != nullptr )
        {
            std::cout << temp->face << std::endl;
            temp = temp->next;
        }
        */
    };

    bool isEmpty() { return false; };
    bool isFull();
    void returnToDeck( card );
    // card draw();
    card peek();
    int size();
    // void empty();

    std::string draw()
    {
        // std::cout << "HIT" << std::endl;
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
        return temp->face; // mem leak
    }
};

class sidePile // my stack
{
private:
    card top;

public:
};
