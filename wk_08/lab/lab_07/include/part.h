#pragma once
#include <iostream>

class part
{
private:
    int SKU;
    std::string description;
    double price;
    std::string UOM;
    int quantityOnHand;
    int leadTime;

public:
    part();

    part( int, std::string, double, std::string, int );
    std::string getPartInfo();
    double getPrice();
    bool inStock();
    bool available( int );

    bool operator>( part );
    bool operator==( part );
    bool operator<( part );
};
