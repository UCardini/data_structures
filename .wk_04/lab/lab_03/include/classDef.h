#pragma once
#include <iostream>
#include <string>

class units
{
private:
    int little; // could be a double for more precision ill wait on it
    int lot;    // lot is 7 littles
    int heap;   // heap is 23 lots

public:
    // constructors
    units();                // default constructor
    units( int, int, int ); // littles lots and heaps
    units( int );           // just littles

    // my functions
    void getValue();                 // prints values in heaps lots and littles
    int onlyLittle( int, int, int ); // changes all units into little's
    int toMeters();                  // changes littles into meters
    void reInitialize( units );
    void resetUnits( int );

    // getters
    int getLittle();
    int getLot();
    int getHeap();

    // setters
    void setLittle( int );
    void setLot( int );
    void setHeap( int );

    // overloaded operators
    void operator+( units );
    void operator-( units );
    void operator*( units );
    void operator/( units );

    bool operator==( units ); // overloaded comparison
    operator std::string();   // overloaded string
};
