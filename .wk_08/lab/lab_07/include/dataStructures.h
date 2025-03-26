#pragma once
#include "exception.h"

template <typename T> class node
{
public:
    T data;
    node* next;
    node* previous;
    node( T data )
    {
        // needs index?
        // for seeAt function would make it easy
        this->data     = data;
        this->next     = nullptr;
        this->previous = nullptr;
    };
};

template <typename T> class doubleLinkedList
{
private:
    node<T>* head;
    node<T>* tail;
    node<T>* current;
    int index;

public:
    doubleLinkedList()
    {
        this->head    = nullptr;
        this->tail    = nullptr;
        this->current = nullptr;
        this->index   = 0;
    };

    void addItem( T inVal )
    {
        node<T>* newNode = new node<T>( inVal );
        if ( this->head == nullptr )
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            newNode->previous = this->tail;
            this->tail->next  = newNode;
            this->tail        = newNode;
        }
        this->index++;
    };

    T* getItem( T inVal )
    {
        /* iii. GetItem – searches the list for the given item. If found, it
         * removes it from the list and returns it. If not found, it returns a
         * null pointer.
         */
        node<T>* temp = this->head;
        if ( !isInList( inVal ) )
        {
            return nullptr;
        }
        while ( temp != nullptr )
        {
            if ( temp->data == inVal )
            {
                if ( temp == this->tail )
                {
                    this->tail = temp->previous;
                    temp->next = nullptr;
                }
                else if ( temp == this->head )
                {
                    this->head = temp->next;
                    if ( this->head != nullptr )
                    {
                        temp->previous = nullptr;
                    }
                }
                else
                {
                    temp->previous->next = temp->next;
                }
                this->index -= 1;
                return &temp->data;
            }
            temp = temp->next;
        }
        return nullptr;
    };

    bool isInList( T inVal )
    {
        /* iv. IsInlist – returns a bool indicating if the given item is in the
         * list.
         */
        node<T>* temp = head;
        while ( temp != nullptr )
        {
            if ( temp->data == inVal )
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    };

    bool isEmpty()
    {
        /* v. IsEmpty – returns a bool indicating if the list is empty. vi. Size
         * – returns an int indicating the number of items in the list.
         */
        return head == nullptr;
    };

    T seeNext()
    {
        /* vii. SeeNext – returns the item without removing it from the list at
         * a given location in the list. The class will maintain the next
         * location and will start at the first item in the list. When it gets
         * to the last item in the list, it will return a null pointer after it
         * gets past the last item. If the list is empty, this will throw an
         * error. 2 calls to SeeNext will return the 2 items next to each other
         * in the list unless SeeAt or Reset is called in between the 2 calls
         * (or the first call returns the last item in the list or the list is
         * modifed between the two calls).
         */
        if ( current == nullptr )
        {

            current = head;
            if ( current == nullptr )
            {
                throw nullNext( "[EXCEPTION] - List is empty!" );
            }
        }
        else
        {
            current = current->next;
        }

        if ( current == nullptr )
        {
            throw nullNext( "[EXCEPTION] - Next value is NULL!" );
        }
        return current->data;
    };

    T seePrev()
    {
        if ( current == nullptr )
        {
            current = tail;
            if ( current == nullptr )
            {
                throw nullPrevious( "[EXCEPTION] - List is empty!" );
            }
        }
        else
        {
            current = current->previous;
        }

        if ( current == nullptr )
        {
            throw nullPrevious( "[EXCEPTION] - Previous value is NULL!" );
        }
        return current->data;
        /* viii. SeePrev – Same as SeeNext except in the other direction.
         */
    };

    T* seeAt( int pos )
    {
        /* ix. SeeAt – Finds an item at a location in the list (int passed in
         * from user), and returns the item without removing it. If the location
         * passed by the user is past the end of the list, this will throw an
         * error. This will set the location used by SeeNext to point at the
         * item after the item returned.
         */
        node<T>* temp = this->current;
        if ( pos > this->index )
        {
            throw overMaxSize(
                "[EXCEPTION] - Position entered exceeds index!" );
        }
        if ( pos < 0 )
        {
            throw underMinSize( "[EXCEPTION] - Position entered below zero!" );
        }

        // needs error handing and other shit
        for ( int i = 0; i < pos; i++ )
        {
            if ( temp == nullptr )
            {
                return nullptr;
            }
            temp = temp->next;
        }
        this->current = temp->next;
        return &temp->data;
    };

    void reset()
    {
        /* x. Reset – resets the location variable that the SeeNext function
         * uses so the next call to SeeNext will return the first item in the
         * list.
         */
        this->current = head;
    };
    ~doubleLinkedList()
    {
        node<T>* current = head;
        while ( current != nullptr )
        {
            node<T>* next = current->next;
            delete current;
            current = next;
        }
    };
    int size()
    {
        /*
         */
        return this->index;
    };

    bool operator>( T );
    bool operator==( T );
    bool operator<( T );
};
