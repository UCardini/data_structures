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
    ~doubleLinkedList();
    void addItem( T* );
    void reset();
    T getItem( T );
    T seeNext();
    T seePrev();
    T seeAt( int );
    int size();
    bool isInList( T );
    bool isEmpty();

    bool operator>( T );
    bool operator==( T );
    bool operator<( T );
};
