#include "part.h"

part::part()
{
    this->SKU            = 0;
    this->description    = "";
    this->price          = 0;
    this->UOM            = "";
    this->quantityOnHand = 0;
}

part::part( int SKU, std::string description, double price, std::string UOM,
            int quantityOnHand )
{
    this->SKU            = SKU;
    this->description    = description;
    this->price          = price;
    this->UOM            = UOM;
    this->quantityOnHand = quantityOnHand;
}

std::string part::getPartInfo()
{
    //
    return "SKU: " + std::to_string( SKU ) +
           ", Description: " + this->description;
}

double part::getPrice()
{
    //
    return price;
}

bool part::inStock()
{
    //
    return this->quantityOnHand > 0;
}

bool part::available( int date )
{
    // No idea how to use this this or what it is for!
    if ( this->quantityOnHand > 0 )
    {
        return this->quantityOnHand > 0;
    }
    else if ( date > this->leadTime )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool part::operator<( part right )
{
    // Need to add implementation in linked list to make sure added item is
    // unique
    return SKU < right.SKU;
}

bool part::operator>( part right )
{
    // Need to add implementation in linked list to make sure added item is
    // unique
    return SKU > right.SKU;
}

bool part::operator==( part right )
{
    // Need to add implementation in linked list to make sure added item is
    // unique
    return SKU == right.SKU;
}

void part::display()
// Reason for displaying price, description, quantity on hand.
// This is primarily what a customer would care about when purchasing a product
// everything else isn't really nessisary!
{
    std::cout << "====================================" << std::endl;
    std::cout << "|" << this->price << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "|" << this->description << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "|" << this->quantityOnHand << std::endl;
    std::cout << "|___________________________________" << std::endl;
}
