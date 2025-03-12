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
// Constructor – This accepts parameters for SKU, Description, Price, and
// UOM. It has an optional parameter for QuantityOnHand which if missing is
// set to 0.
{
    this->SKU            = SKU;
    this->description    = description;
    this->price          = price;
    this->UOM            = UOM;
    this->quantityOnHand = quantityOnHand;
}

std::string part::getPartInfo()
{
    return std::to_string( SKU ) + this->description;
} // – this returns a string containing both SKU
  // concatenated with
double part::getPrice() { return price; };

bool part::inStock()
{ //
    return this->quantityOnHand > 0;
}
// – returns a bool indicating if the Quantity On Hand is >0.
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
