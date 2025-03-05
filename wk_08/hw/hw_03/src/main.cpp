// #include "classDef.h"

#include <iostream>
#include <string>
int main()
{
    int value;
    int suit;
    std::string face;

    std::cout << "Enter value: ";
    std::cin >> value;
    std::cout << std::endl;
    std::cout << "Enter suit: ";
    std::cin >> suit;
    std::cout << std::endl;

    switch ( value )
    {
    case 1:
        value = 1;
        face  = "Ace";
        break;
    case 2:
        value = 2;
        face  = "Deuce";
        break;
    case 3:
        value = 3;
        face  = "Three";
        break;
    case 4:
        value = 4;
        face  = "Four";
        break;
    case 5:
        value = 5;
        face  = "Five";
        break;
    case 6:
        value = 6;
        face  = "Six";
        break;
    case 7:
        value = 7;
        face  = "Seven";
        break;
    case 8:
        value = 8;
        face  = "Eight";
        break;
    case 9:
        value = 9;
        face  = "Nine";
        break;
    case 10:
        value = 10;
        face  = "Ten";
        break;
    case 11:
        value = 11;
        face  = "Jack";
        break;
    case 12:
        value = 12;
        face  = "Queen";
        break;
    case 13:
        value = 13;
        face  = "King";
        break;
    }

    face += " of ";

    switch ( suit )
    {
    case 1:
        suit = 1;
        face += "Hearts";
        break;
    case 2:
        suit = 2;
        face += "Diamonds";
        break;
    case 3:
        suit = 3;
        face += "Spades";
        break;
    case 4:
        suit = 4;
        face += "Clubs";
        break;
    }

    std::cout << face << std::endl;

    return 0;
}
