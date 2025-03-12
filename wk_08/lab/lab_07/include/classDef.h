#pragma once
#include <iostream>
#include <string>

template <typename T> class node
{
public:
    T data;
    node* next;
    node* previous;
    node( T data )
    {
        this->data     = data;
        this->next     = nullptr;
        this->previous = nullptr;
    }
};

class stock
{
private:
    int SKU; // – stock keeping number
    std::string description;
    double price;
    std::string UOM;
    //- Unit of measure (is it sold by the foot, pound, each, etc…)
    int quantityOnHand = 0;
    int leadTime; //(number of days it takes to order if there aren’t any on
                  // hand to sell)
public:
    stock()
    {
        this->SKU            = 0;
        this->description    = "";
        this->price          = 0;
        this->UOM            = "";
        this->quantityOnHand = 0;
    };

    stock( int SKU, std::string description, double price, std::string UOM,
           int quantityOnHand )
    {
        this->SKU            = SKU;
        this->description    = description;
        this->price          = price;
        this->UOM            = UOM;
        this->quantityOnHand = quantityOnHand;
    };
    // Constructor – This accepts parameters for SKU, Description, Price, and
    // UOM. It has an optional parameter for QuantityOnHand which if missing is
    // set to 0.
    std::string getPartInfo()
    {
        return std::to_string( SKU ) + description;
    }; // – this returns a string containing both SKU
       // concatenated with
    double getPrice() { return price; };
    bool inStock()
    { //
        return quantityOnHand > 0;
    };
    // – returns a bool indicating if the Quantity On Hand is >0.
    bool available( int date )
    // Takes desired date and checks if desired date > leadTime
    {
        if ( quantityOnHand > 0 )
        {
            return quantityOnHand > 0;
        }
        else if ( date > leadTime )
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    bool operator>( stock );
    bool operator==( stock );
    bool operator<( stock );
};

// overloaded Comparisons
bool stock::operator<( stock right ) { return SKU < right.SKU; }
bool stock::operator>( stock right ) { return SKU > right.SKU; }
bool stock::operator==( stock right ) { return SKU == right.SKU; }

template <typename T> class doubleLinkedList
{
private:
    T* head;

public:
    doubleLinkedList( T* head ) { this->head = head; };

    void addItem( T* current );
    void reset();
    T getItem( T current );
    T seeNext();
    T seePrev();
    T seeAt( int pos );
    int size();
    bool isInList( T current );
    bool isEmpty();
};
