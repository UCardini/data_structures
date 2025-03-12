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
    return std::to_string( SKU ) + this->description;
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
    //
    return SKU < right.SKU;
}

bool part::operator>( part right )
{
    //
    return SKU > right.SKU;
}

bool part::operator==( part right )
{
    //
    return SKU == right.SKU;
}
