#pragma once
#include "exception.h"

template <typename T> class entertainmentCollection
{
public:
    static const int shelfSize = 1; // hard limit for the shelf size...
    T* items[ shelfSize ];
    int nextItem;

    entertainmentCollection<T>()
    { // Default constructor
        nextItem = 0;
    };

    void shelfAdd( T* item )
    { // Checks next index to see if it goes overfull
        if ( shelfSize <= nextItem )
        { // Throws fullShelf exception
            delete item;
            throw fullShelf( "Shelf is full", shelfSize );
        }
        else
        { // Adds new item to the stack if it fits
            this->items[ nextItem ] = item;
            nextItem++;
        }
    };

    T* shelfRemove()
    { // Checks if current index is less or equal to zero
        if ( nextItem <= 0 )
        { // Throws emptyShelf exception
            throw emptyShelf( "Shelf is empty" );
        }
        else
        { // Decrements index effectively removing from stack
            nextItem--;
            return items[ nextItem ];
        }
    };

    int getIndex() { return nextItem; };

    /*  The shelf add method was created following the constraints of a stack
     *  this means that first into the stack is the last out of it and so need
     *  to make sure that the size never exceeds the limit of our stack and when
     *  it does it throws an exception and gives an explaination on what the
     *  available options are they can use.
     *  Essentially if the size of the stack is under our global constant for
     *  size it will add an element into the stack and if it goes over it throws
     *  an exception.
     *  The same is true of the shelf remove method except it checks if the
     * stack contains anything. If the contents of the shelf stack are empty
     * then throw an exception otherwise it decrements the stacks size and
     * returns the movie.
     */
};
