#include "../include/classDef.h"
// default constructer initializes member variables to 0 when used.
units::units()
{
    little = 0;
    lot    = 0;
    heap   = 0;
}

// this constructer is used when we want to define each member
units::units( int little, int lot, int heap )
{
    this->little = little;
    this->lot    = lot;
    this->heap   = heap;
}

// this constructer is used when we want to give it just littles
units::units( int little )
{
    this->little = little % 7;          // more than 7 little's is a lot
    lot          = ( little / 7 ) % 23; // more than 23 lot's is a heap
    heap = little / ( 7 * 23 ); // largest metric in skibidi sigma rizz units
}

/*   Name: getValue()
 *  Input: None
 * Output: Void
 * ****** Description ******
 * This function prints all the units
 * values (little, lot, heap).
 */
void units::getValue() // print member funtion
{
    std::cout << "There are: " << heap << " heaps, " << lot << " lot's, and "
              << little << " little's" << std::endl;
}

/*   Name: onlyLittle()
 *  Input: int(little, lot, heap)
 * Output: int little
 * ****** Description ******
 * This function converts all units back
 * into littles.
 */
int units::onlyLittle( int little, int lot, int heap )
{
    little = ( heap * 23 * 7 ) + ( lot * 7 ) + little;
    return little;
}

/*   Name: toMeters()
 *  Input: none
 * Output: int value (in meters)
 * ****** Description ******
 * This function converts the units littles
 * lots and heaps into just meters this
 * conversion is 1:1 for littles to meters
 * We convert all sizes of our units into littles
 * then we return the output of that.
 */
int units::toMeters() { return onlyLittle( little, lot, heap ); }

/*   Name: reInitialize()
 *  Input: units newUnits
 * Output: none
 * ****** Description ******
 * This function changes the value of littles
 * lots and heaps to the value of the input
 */
void units::reInitialize( units newUnits )
{
    little = newUnits.little;
    lot    = newUnits.lot;
    heap   = newUnits.heap;
}

/*   Name: resetUnits()
 *  Input: int little
 * Output: none
 * ****** Description ******
 * This function takes a value in littles and
 * coverts it into littles lots and heaps
 */
void units::resetUnits( int little )
{
    this->little = little % 7;          // more than 7 little's is a lot
    lot          = ( little / 7 ) % 23; // more than 23 lot's is a heap
    heap = little / ( 7 * 23 ); // largest metric in skibidi sigma rizz units
}

// getters
int units::getLittle() { return little; }
int units::getLot() { return lot; }
int units::getHeap() { return heap; }

// setters
void units::setLittle( int little ) { this->little = little; }
void units::setLot( int lot ) { this->lot = lot; }
void units::setHeap( int heap ) { this->heap = heap; }

// overloaded operators
// Addition - We convert heaps and lots into littles and add it to
// the right variable we then call a constructer to convert it back
// into littles lots and heaps
void units::operator+( units right )
{
    little += right.little;
    lot += right.lot;
    heap += right.heap;

    resetUnits( onlyLittle( little, lot, heap ) );
}
// Subtraction - We convert heaps and lots into littles and subtract
// it by the right variable we then call a constructer to turn it back
// into little lots and heaps
void units::operator-( units right )
{
    little -= right.little;
    lot -= right.lot;
    heap -= right.heap;
    resetUnits( onlyLittle( little, lot, heap ) );
}
// Multiplication - We multiply left variable little lots and heaps
// by the right little lots and heaps straight accross we the call
// our constructer to create a new object so we dont desturb our
// initial values
void units::operator*( units right )
{
    /* ASIDE
     * didn't know if i should multiply straight accross or by the
     * littles/meters if i have 1m and multiply it by 1m
     * i simply have 1m... if i have 100cm and multiply it by
     * 100cm i have 10_000cm or 100m i thought this would be the most
     * for accuracys sake i chose the ladder.
     */
    little *= right.little;
    lot *= right.lot;
    heap *= right.heap;
    resetUnits( onlyLittle( little, lot, heap ) );
}
// Division - We turn left and right into littles check if its divided
// by zero and return (-1337,-1337,-1337) if it is and left/right if it isn't
void units::operator/( units right )
{
    int rightLittle = onlyLittle( right.little, right.lot, right.heap );

    if ( rightLittle == 0 )
    {
        std::cout << "\t---Error Divide by zero! (enter a value greater than "
                     "zero for y)---"
                  << std::endl;
        little = -1337;
        lot    = -1337;
        heap   = -1337; // leet value error
    }
    else
    {
        if ( right.heap != 0 )
        {
            heap /= right.heap;
        }
        else
        {
            heap = 0;
        }
        if ( right.lot != 0 )
        {
            lot /= right.lot;
        }
        else
        {
            lot = 0;
        }
        if ( right.little != 0 )
        {
            little /= right.little;
        }
        else
        {
            little = 0;
        }
    }

    resetUnits( onlyLittle( little, lot, heap ) );
}
// Comparison - We convert left and right into littles and
// see if theyre equal if they are return true else false
bool units::operator==( units right )
{
    int rightLittle = onlyLittle( right.little, right.lot, right.heap );
    int leftLittle  = onlyLittle( little, lot, heap );
    if ( rightLittle == leftLittle )
    {
        return true;
    }
    else
        return false;
}

// To string - This converts the unit type to a string so
// we can print it out works like an overloaded operator
// by overloading string we can cast our defined units as
// a string.
units::operator std::string()
{
    std::string unitString = std::to_string( heap ) + " heaps, " +
                             std::to_string( lot ) + " lots, and " +
                             std::to_string( little ) + " littles.";
    return unitString;
}
