#pragma once
#include "exception.h"

template <typename T> class stack
{
public:
    // constructor
    stack( int );

    // functions
    void push( T* inVal );
    T* pop();
    T* top();
    int length();
    void empty();

private:
    int size;
    int nextItem;
    T** items;

public: // defaults
    stack();
    stack( stack&& )                 = default;
    stack( const stack& )            = default;
    stack& operator=( stack&& )      = default;
    stack& operator=( const stack& ) = default;
    ~stack();
};

template <typename T> class queue
{
public:
    // constructor
    queue( int );

    // functions
    bool isEmpty();
    bool isFull();
    void enqueue( T* );
    T* dequeue();
    T* peek();
    int size();
    void empty();

private:
    int capacity;
    int tail;
    int head;
    T** items;

public: // defaults
    queue();
    queue( queue&& )                 = default;
    queue( const queue& )            = default;
    queue& operator=( queue&& )      = default;
    queue& operator=( const queue& ) = default;
    ~queue();
};

// overloaded constructors
template <typename T> stack<T>::stack( int size )
{
    this->size     = size;
    this->items    = new T*[ size ];
    this->nextItem = 0;
}
template <typename T> queue<T>::queue( int capacity )
{
    this->capacity = capacity;
    this->items    = new T*[ capacity ];
    this->head     = 0;
    this->tail     = 0;
}

// deconstructors
template <typename T> stack<T>::~stack() 
{
    delete[] this->items;
}
template <typename T> queue<T>::~queue() 
{
    delete[] this->items;
}

/**
 * push
 * @brief Places pointer on the top of the stack
 * @param Pointer to item to put into the stack
 *
 * @verbose
 * This function checks if the array is exceeded by next item where it
 * throws a stackOverflow exception. If the stack isn't full it'll add the
 * input value to the items array at the index nextItem then it increments
 * nextItem (index in array).
 */
template <typename T> void stack<T>::push( T* inVal )
{
    if ( size <= nextItem )
    {
        delete inVal;
        throw stackOverflow(
            "[Stack Overflow] - cannot add item to filled stack" );
    }
    else
    {
        items[ nextItem ] = inVal;
        nextItem++;
    }
}

/**
 * pop
 * @brief Remove and return last added item pointer
 * @return Pointer to item that was removed
 *
 * @verbose
 * This function checks the top of the stack to see if it's equal to 0 where
 * it'll throw a stackUnderflow exception. If it isn't equal to 0 it'll
 * decrement the top position return the item to the user.
 */
template <typename T> T* stack<T>::pop()
{
    if ( nextItem <= 0 )
    {
        throw stackUnderflow(
            "[Stack Underflow] - cannot remove item from empty stack" );
    }
    else
    {
        nextItem--;
        return items[ nextItem ];
    }
}

/**
 * top
 * @brief Returns item pointer on top of the stack
 * @return Most recent entry into the stack
 *
 * @verbose
 * This function checks if the stack is equal to 0 where it'll throw a
 * stackUnderflow exception. If it isn't equal to 0 it'll return the top
 * item pointer.
 */
template <typename T> T* stack<T>::top()
{
    if ( nextItem <= 0 )
    {
        throw stackUnderflow(
            "[Stack Underflow] - no item to view, stack is empty" );
    }
    else
    {
        return items[ nextItem - 1 ];
    }
}

/**
 * length
 * @brief Returns the length of the stack as an integer
 * @return Length of the stack
 *
 * @verbose
 * This function returns size of the array.
 */
template <typename T> int stack<T>::length() { return nextItem; }

/**
 * empty
 * @brief Delete all pointers in items array
 *
 * @verbose
 * This function while the items array isn't equal to 0 itterates and
 * deletes the pointers in the nextItem positions of the array and
 * decrements nextItem until theres no items in the array.
 */
template <typename T> void stack<T>::empty()
{
    this->nextItem = 0;
    this->~stack();
}

/**
 * isEmpty
 * @brief Checks if the queue is empty
 * @return true when empty, false when items still in queue
 *
 * @verbose
 * This function returns the boolean value of head == tail, this checks if
 * it's empty because if theres no difference between head and tail then
 * theres no pointers in the array.
 */
template <typename T> bool queue<T>::isEmpty() { return head == tail; }

/**
 * isFull
 * @brief Check if queue is full
 * @return true when full, false when not full
 *
 * @verbose
 * This function returns the boolean value of tail + 1 == head, this checks
 * if it's full because if theres 1 position between head and tail then
 * there's no more avaiable positions for a new pointer to occupy.
 */
template <typename T> bool queue<T>::isFull()
{
    return ( tail + 1 ) % capacity == head;
}

/**
 * enqueue
 * @brief Places pointer at the tail (relative last) position index of the
 * array
 * @param Pointer to item you're putting into the queue
 *
 * @verbose
 * This function checks if the array is full where it throws a queueOverflow
 * exception and deletes the input value. If the queue isn't full it'll
 * increment the tail (relative last) position in the array set the items
 * array at the tail position equal to the input value.
 */
template <typename T> void queue<T>::enqueue( T* inVal )
{
    if ( isFull() )
    {
        delete inVal;
        throw queueOverflow(
            "[Queue Overflow] - cannot add item to filled queue" );
    }
    else
    {
        tail          = ( tail + 1 ) % capacity;
        items[ tail ] = inVal;
    }
}

/**
 * dequeue
 * @brief Removes and returns pointer at head (relative first) in
 * the array
 * @return pointer at the head position of the array
 *
 * @verbose
 * This function checks if the queue is empty where it'll throw a
 * queueUnderflow exception. If it isn't empty it'll increment the head
 * (relative first) position in the array and return it's pointer.
 */
template <typename T> T* queue<T>::dequeue()
{
    if ( isEmpty() )
    {
        throw stackUnderflow(
            "[Queue Underflow] - cannot remove item from empty queue" );
    }
    else
    {
        head = ( head + 1 ) % capacity;
        return items[ head ];
    }
}

/**
 * peek
 * @brief Returns the pointer at head (relative first position) in the array
 * @return Item in the head position of the items array
 *
 * @verbose
 * This function checks if the queue is empty where it'll throw a
 * queueUnderflow exception. If it isn't empty it'll return the pointer at
 * the head (relative first) position of the array.
 */
template <typename T> T* queue<T>::peek()
{
    if ( isEmpty() )
    {
        throw queueUnderflow(
            "[Queue Underflow] - no item to view, queue is empty" );
    }
    else
    {
        return items[ ( head + 1 ) % capacity ];
    }
}

/**
 * size
 * @brief Returns size of the items array as an int
 * @return Size of the queue
 *
 * @verbose
 * This function takes the 2 cases for the circular queue. The first case
 * when the tail is less or equal too the tail, where it finds and returns
 * the difference of tail and head. The second case when the tail is less
 * than the head, where it finds the difference of the capacity of the array
 * and the sums the relative positions of head and tail.
 */
template <typename T> int queue<T>::size()
{
    if ( head <= tail )
    {
        return tail - head;
    }
    else
    {
        return capacity - head + tail;
    }
}

/**
 * empty
 * @brief Delete all pointers in the items array
 *
 * @verbose
 * This function while the items array isn't empty itterates and deletes the
 * pointers in the head (first relative) positions of the array.
 */
template <typename T> void queue<T>::empty()
{
    this->head=0;
    this->tail=0;
    this->~queue();

}
