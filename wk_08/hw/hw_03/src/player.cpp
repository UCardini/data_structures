#include "player.h"
#include "exception.h"
#include <string>

sidePile::sidePile() { this->top = 0; }

std::string sidePile::display( card* inVal ) { return inVal->face; }
void sidePile::push( card* inVal )
{
    if ( top >= this->size )
    {
        throw stackOverflow( "[EXCEPTION] - Stack Overflow" );
    }
    inVal->next  = nullptr;
    stack[ top ] = inVal;
    top++;
}

card* sidePile::pop()
{
    if ( top < 1 )
    {
        throw stackUnderflow( "[EXCEPTION] - Stack Underflow" );
    }
    top--;
    return stack[ top ];
}

int sidePile::remaining() { return this->size - this->top; }
