#pragma once
#include <iostream>

template <typename T> class stack
{
public:
    stack();
    stack( int );
    stack( stack&& )                 = default;
    stack( const stack& )            = default;
    stack& operator=( stack&& )      = default;
    stack& operator=( const stack& ) = default;
    ~stack();

private:
    int size;
    int nextItem;
    T** items;

public:
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
    void push( T* inVal )
    {
        if ( size <= nextItem )
        {
            delete inVal;
            std::cout << "HIT" << std::endl;
            // throw stackOverflow();
        }
        else
        {
            items[ nextItem ] = inVal;
            nextItem++;
        }
    };

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
    T* pop()
    {
        if ( nextItem <= 0 )
        {
            // throw stackUnderflow();
        }
        else
        {
            nextItem--;
            return items[ nextItem ];
        }
    };

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
    T* top()
    {
        if ( nextItem <= 0 )
        {
            // throw stackUnderflow();
        }
        else
        {
            return items[ nextItem - 1 ];
        }
    };

    /**
     * length
     * @brief Returns the length of the stack as an integer
     * @return Length of the stack
     *
     * @verbose
     * This function returns size of the array.
     */
    int length() { return nextItem; };

    /**
     * empty
     * @brief Delete all pointers in items array
     *
     * @verbose
     * This function while the items array isn't equal to 0 itterates and
     * deletes the pointers in the nextItem positions of the array and
     * decrements nextItem until theres no items in the array.
     */
    void empty()
    {
        while ( 0 <= nextItem )
        {
            delete items[ nextItem ];
            nextItem--;
        }
    }
};

template <typename T> class queue
{
public:
    queue();
    queue( int );
    queue( queue&& )                 = default;
    queue( const queue& )            = default;
    queue& operator=( queue&& )      = default;
    queue& operator=( const queue& ) = default;
    ~queue();

private:
    int capacity;
    int tail;
    int head;
    T** items;

public:
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
    bool isEmpty() { return head == tail; };

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
    bool isFull() { return ( tail + 1 ) % capacity == head; };

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
    void enqueue( T* inVal )
    {
        if ( isFull() )
        {
            delete inVal;
            // throw queueOverflow();
        }
        else
        {
            tail          = ( tail + 1 ) % capacity;
            items[ tail ] = inVal;
        }
    };

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
    T* dequeue()
    {
        if ( isEmpty() )
        {
            // throw stackUnderflow();
        }
        else
        {
            head = ( head + 1 ) % capacity;
            return items[ head ];
        }
    };

    /**
     * top
     * @brief Returns the pointer at head (relative first position) in the array
     * @return Item in the head position of the items array
     *
     * @verbose
     * This function checks if the queue is empty where it'll throw a
     * queueUnderflow exception. If it isn't empty it'll return the pointer at
     * the head (relative first) position of the array.
     */
    T* peek()
    {
        if ( isEmpty() )
        {
            // throw stackUnderflow();
        }
        else
        {
            return items[ ( head + 1 ) % capacity ];
        }
    };

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
    int size()
    {
        if ( head <= tail )
        {
            return tail - head;
        }
        else
        {
            return capacity - head + tail;
        }
    };

    /**
     * empty
     * @brief Delete all pointers in the items array
     *
     * @verbose
     * This function while the items array isn't empty itterates and deletes the
     * pointers in the head (first relative) positions of the array.
     */
    void empty()
    {
        while ( !isEmpty() )
        {
            head = ( head + 1 ) % capacity;
            delete items[ head ];
        }
    };
};

template <typename T> stack<T>::stack( int size )
{
    this->size     = size;
    this->items    = &items[ size ];
    this->nextItem = 0;
};

template <typename T> stack<T>::~stack(){};

template <typename T> queue<T>::queue( int capacity )
{
    this->capacity = capacity;
    this->items    = &items[ capacity ];
    this->head     = 0;
    this->tail     = 0;
};

template <typename T> queue<T>::~queue(){};
