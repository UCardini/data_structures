#pragma once // pragma three times... how many times should I use this
#include "exception.h"

template <typename T> class entertainmentCollection
{
public:
    static const int shelfSize = 10; // hard limit for the shelf size...
    T* items[ shelfSize ];           // ptr is required
    int nextItem;                    // index of the next item

    // Default constructor
    entertainmentCollection<T>() { nextItem = 0; };

    /*   Name: shelfAdd()
     *  Input: ptr to item going on shelf
     * Output: none
     * ****** Description ******
     * This function checks if the next item in the stack exceed the global
     * limit thats set for shelf size. If it does exceed the capacity of the
     * shelf it deletes the pointer to item that is created in
     * addGame()/addMovie() functions inside main.cpp and throws a fullShelf
     * exception. If the capacity isn't exceeded the item in the array at the
     * position of the next item is set to the item created in those functions
     * (addGame()/addMovie()).
     */
    void shelfAdd( T* item )
    { // Checks next index to see if it goes overfull
        if ( shelfSize <= nextItem )
        { // Throws fullShelf exception
            delete item;
            throw fullShelf( "Shelf is full" );
        }
        else
        { // Adds new item to the stack if it fits
            this->items[ nextItem ] = item;
            /* dont delete item here the array contains a bunch of memory
             * addresses by deleting item you delete the value contained in the
             * address stored in the array
             */
            nextItem++;
        }
    };

    /*   Name: shelfRemove()
     *  Input: none
     * Output: ptr to last item entered into shelf stack
     * ****** Description ******
     * This function checks if the items in the stack are less than 0,
     * for which the stack/shelf is empty at zero. If the stack is less equal to
     * 0 it will throw an emptyShelf exception. If there's items remaining in
     * the stack then the index it decremented to return the item thats being
     * removed and shelfAdd replaces the item removed.
     */
    T* shelfRemove()
    { // Checks if current index is less or equal to zero
        if ( nextItem <= 0 )
        { // Throws emptyShelf exception
            throw emptyShelf( "Shelf is empty" );
        }
        else
        { // Decrements index effectively removing from stack
            nextItem--;
            /* ptr gets deleted in main.cpp this was just the easiest way given
             * theres no real way of doing it in here bc the item has to be
             * returned to main per the instructions, otherwise I would have
             * this handle deleting and printing
             */
            return items[ nextItem ];
        }
    };

    /*   Name: getIndex()
     *  Input: none
     * Output: integer nextItem index
     * ****** Description ******
     * This Function returns the integer nextItem, because we start our index at
     * zero and end it effectively at 9 because shelfAdd throws an exception if
     * shelfSize is less than or equal to nextItem, we can return just the next
     * item because reading it as 1-10 is better than reading it as the index
     * the array reads (being 0-9).
     */
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
