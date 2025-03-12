#pragma once

template <typename T> class node
{
public:
    T data;
    node* next;
    node* previous;
    node( T data );
};

template <typename T> class doubleLinkedList
{
private:
    T* head;

public:
    doubleLinkedList( T* );
    void addItem( T* );
    T getItem( T );
    bool isInList( T );
    bool isEmpty();
    T seeNext();
    T seePrev();
    T seeAt( int );
    void reset();
    ~doubleLinkedList();
    int size();

    bool operator>( T );
    bool operator==( T );
    bool operator<( T );
};
