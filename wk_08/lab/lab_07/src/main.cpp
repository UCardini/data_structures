#include "dataStructures.h"
#include "exception.h"
#include "part.h"
#include <iostream>
#include <string>

std::string printFunctions();
part newPart();
int main()
{
    doubleLinkedList<part> list;
    while ( true )
    {
        std::string selection = printFunctions();
        if ( selection == "1" )
        {
            part p = newPart();
            list.addItem( p );
        }

        else if ( selection == "2" )
        {
            std::cout << "Enter a part to get from linked list!" << std::endl;

            part p             = newPart();
            std::string inList = list.getItem( p )->getPartInfo();
        }
        else if ( selection == "3" )
        {
            std::cout << "Enter a part to check if it in linked list!"
                      << std::endl;

            part p = newPart();

            if ( list.isInList( p ) )
            {
                std::cout << "Part is in List!" << std::endl;
            }
            else
            {
                std::cout << "Part is NOT in List!" << std::endl;
            }
        }
        else if ( selection == "4" )
        {
            if ( list.isEmpty() )
            {
                std::cout << "List is empty!" << std::endl;
            }
            else
            {
                std::cout << "List is NOT empty!" << std::endl;
            }
            break;
        }

        else if ( selection == "5" )
        {
            std::string inList;
            try
            {
                inList = list.seeNext().getPartInfo();
            }
            catch ( nullNext e )
            {
                std::cerr << e.msg << std::endl;
                inList = "Next item in list is null!";
            }
            std::cout << inList << std::endl;
        }
        else if ( selection == "6" )
        {
            std::string inList;
            try
            {
                inList = list.seePrev().getPartInfo();
            }
            catch ( underMinSize e )
            {
                std::cerr << e.msg << std::endl;
                inList = "Previous item in list is null!";
            }
            std::cout << inList << std::endl;
        }
        else if ( selection == "7" )
        {
            int pos;
            std::cout << "Enter the position of the item: ";
            std::cin >> pos;
            std::cout << std::endl;
            std::string inList = "Item is NOT in list!";
            try
            {
                inList = list.seeAt( pos )->getPartInfo();
            }
            catch ( nullNext e )
            {
                std::cerr << e.msg << std::endl;
            }
            catch ( nullPrevious e )
            {
                std::cerr << e.msg << std::endl;
            }
            std::cout << inList << std::endl;
        }
        else if ( selection == "8" )
        {
            list.reset();
        }
        else if ( selection == "9" )
        {
            std::cout << "Size of list is: " << list.size() << std::endl;
        }
        else if ( selection == "0" )
        {
            break;
        }
        else
        {
            std::cerr << "[ERROR] - Value entered not a valid option!"
                      << std::endl;
        }
    }
    return 0;
}

std::string printFunctions()
{
    std::string outVal;
    std::cout << "Select a member function to test: " << std::endl;
    std::cout << " #: \t name:" << std::endl;
    std::cout << "[1] \t addItem( T* )" << std::endl;
    std::cout << "[2] \t getItem( T )" << std::endl;
    std::cout << "[3] \t isInList( T )" << std::endl;
    std::cout << "[4] \t isEmpty()" << std::endl;
    std::cout << "[5] \t seeNext()" << std::endl;
    std::cout << "[6] \t seePrev()" << std::endl;
    std::cout << "[7] \t seeAt( int )" << std::endl;
    std::cout << "[8] \t reset()" << std::endl;
    std::cout << "[9] \t size()" << std::endl;
    std::cout << "[0] \t Exit Program!" << std::endl;

    std::cout << "Enter your selection: ";
    std::cin >> outVal;
    std::cout << std::endl;

    return outVal;
}

part newPart()
{
    int SKU;
    std::string description;
    double price;
    std::string UOM;
    int quantityOnHand = 0;

    std::cout << "You selected addItem!" << std::endl;
    std::cout << "Please enter the following information:" << std::endl;
    std::cout << "Enter the SKU #: ";
    std::cin >> SKU;
    std::cout << std::endl;
    std::cout << "Enter the Description: ";
    std::cin >> description;
    std::cout << std::endl;
    std::cout << "Enter the price: $";
    std::cin >> price;
    std::cout << std::endl;
    std::cout << "Enter the UOM: ";
    std::cin >> UOM;
    std::cout << std::endl;

    std::string qtyh = " ";
    std::cout << "Would you like to enter the quantity on hand? [1 = yes]: ";
    std::cin >> qtyh;
    std::cout << std::endl;
    if ( qtyh == "1" )
    {
        std::cout << "(OPTIONAL) - Enter the quantity on hand: ";
        std::cin >> quantityOnHand;
    }
    part p( SKU, description, price, UOM, quantityOnHand );
    return p;
}
