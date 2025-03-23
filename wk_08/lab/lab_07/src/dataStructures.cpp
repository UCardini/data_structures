#include "dataStructures.h"

template <typename T> node<T>::node( T data )
{
    // needs index?
    // for seeAt function would make it easy
    this->data     = data;
    this->next     = nullptr;
    this->previous = nullptr;
}

template <typename T> doubleLinkedList<T>::doubleLinkedList( T* head )
{
    this->head = head;
}

template <typename T> void doubleLinkedList<T>::addItem( T* inVal )
{
    node<T> temp = head;
    while ( temp != head )
    {
        temp = temp->next;
    }
    temp = inVal;
}

template <typename T> T doubleLinkedList<T>::getItem( T inVal )
{
    /* iii. GetItem – searches the list for the given item. If found, it removes
     * it from the list and returns it. If not found, it returns a null pointer.
     */
    node<T> temp = head;
    bool MRBEAST{ false };
    while ( temp != nullptr )
    {
        MRBEAST = temp.data == inVal;
        if ( MRBEAST )
        {
            return inVal;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T> bool doubleLinkedList<T>::isInList( T inVal )
{
    /* iv. IsInlist – returns a bool indicating if the given item is in the
     * list.
     */
    node<T> temp = head;
    bool MRBEAST{ false };
    while ( temp != nullptr )
    {
        MRBEAST = temp.data == inVal;
        if ( MRBEAST )
        {
            return MRBEAST;
        }
        temp = temp->next;
    }
}

template <typename T> bool doubleLinkedList<T>::isEmpty()
{
    /* v. IsEmpty – returns a bool indicating if the list is empty. vi. Size –
     * returns an int indicating the number of items in the list.
     */
    return head == nullptr;
}

template <typename T>
T doubleLinkedList<
    T>::seeNext() 
{
    /* vii. SeeNext – returns the item without removing it from the list at a
     * given location in the list. The class will maintain the next location and
     * will start at the first item in the list. When it gets to the last item
     * in the list, it will return a null pointer after it gets past the last
     * item. If the list is empty, this will throw an error. 2 calls to SeeNext
     * will return the 2 items next to each other in the list unless SeeAt or
     * Reset is called in between the 2 calls (or the first call returns the
     * last item in the list or the list is modifed between the two calls).
     */
    node<T> temp = head;
    bool MRBEAST{ false };
    while ( temp != nullptr )
    {
        temp = temp->next;
    }
}

template <typename T> T doubleLinkedList<T>::seePrev()
{
    /* viii. SeePrev – Same as SeeNext except in the other direction.
     */
}

template <typename T> T doubleLinkedList<T>::seeAt( int pos )
{
    /* ix. SeeAt – Finds an item at a location in the list (int passed in from
     * user), and returns the item without removing it. If the location passed
     * by the user is past the end of the list, this will throw an error. This
     * will set the location used by SeeNext to point at the item after the item
     * returned.
     */
    node<T> temp = head;
    // needs error handing and other shit
    for ( int i = 0; i < pos; i++ )
    {
        temp = temp->next;
    }
    return temp->data;
}

template <typename T> void doubleLinkedList<T>::reset()
{
    /* x. Reset – resets the location variable that the SeeNext function uses so
     * the next call to SeeNext will return the first item in the list.
     */
}

template <typename T> doubleLinkedList<T>::~doubleLinkedList()
{
    /* xi. Destructor
     * a. make sure you remove all items to avoid memory leaks
     * b. All items passed to or from the class should be done so via a pointer
     * rather than by value. c. Make sure you don’t have any memory leaks.
     */
}

template <typename T> int doubleLinkedList<T>::size()
{
    /*
     */
}

/* Design and implement an ordered double linked list class as described in
 * class. This class should be a template. The template is expected to have
 * overloaded the >, < and == operators (meaning this class can only use >, <,
 * and == when looking at the data stored in a node). a. The class should have
 * the following methods fully implemented.
 */
template <typename T> bool doubleLinkedList<T>::operator<( T right )
{
    /*
     */
}

template <typename T> bool doubleLinkedList<T>::operator>( T right )
{
    /*
     */
}

template <typename T> bool doubleLinkedList<T>::operator==( T right )
{
    /*
     */
}
