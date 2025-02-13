#include "classDef.h"

void operationCases( int, int );

int main()
{
    while ( true )
    {
        std::string operation = "";
        int x                 = 0;
        int y                 = 0;

        std::cout << "Please enter a distance for x (in Meters): " << std::endl;
        std::cin >> x;
        std::cout << "Please enter a distance for y (in Meters): " << std::endl;
        std::cin >> y;

        operationCases( x, y );

        std::cout << "Would you like continue? Type 1 "
                     "to restart: ";
        char restart = ' ';
        std::cin >> restart;
        if ( restart != '1' )
            break;
    }
    return 0;
}

/*   Name: operationCases
 *  Input: x and y in meters
 * Output: Void
 *
 * ****** Description ******
 * This function takes x and y in meters
 * and converts it to our made up units
 * X and Y, it then prompts the user for
 * which operation they want to do (+,-,*,/,==).
 * It then calculates the operation and prints
 * the output.
 */
void operationCases( int x, int y )
{
    units X( x ); // The conversion for littles is 1:1 so we can just
    units Y( y ); // use the constructor we made for total littles
    units R( x ); // resets X

    int selection = 0;
    std::cout << "_____________________________________" << std::endl;
    std::cout << "1. Addition operation (x + y)" << std::endl;
    std::cout << "2. Subtraction operation (x - y)" << std::endl;
    std::cout << "3. Multiplication operation (x * y)" << std::endl;
    std::cout << "4. Division operation (x / y)" << std::endl;
    std::cout << "5. Comparison operation (x == y)" << std::endl;
    std::cout << "6. Test all operations (x +-*/== y)" << std::endl;
    std::cout << "-------------------------------------" << std::endl
              << std::endl;

    std::cout << "Make a selection (1 to 6) to select operation: ";
    std::cin >> selection;

    if ( selection == 1 )
    {
        ( X + Y );
        std::cout << "Addition operation (x + y) = "
                  << static_cast<std::string>( X ) << std::endl;
    }
    else if ( selection == 2 )
    {
        ( X - Y );
        std::cout << "Subtraction operation (x - y) = "
                  << static_cast<std::string>( X ) << std::endl;
    }
    else if ( selection == 3 )
    {
        ( X * Y );
        std::cout << "Multiplication operation (x * y) = "
                  << static_cast<std::string>( X ) << std::endl;
    }
    else if ( selection == 4 )
    {
        ( X / Y );
        std::cout << "Division operation (x / y) = "
                  << static_cast<std::string>( X ) << std::endl;
    }
    else if ( selection == 5 )
    {
        if ( X == Y )
        {
            std::cout << "Comparison operation (x == y) = true" << std::endl;
        }
        else
            std::cout << "Comparison operation (x == y) = false" << std::endl;
    }
    else if ( selection == 6 )
    {
        std::cout << "getValue() function:" << std::endl;
        X.getValue();
        Y.getValue();

        std::cout << "toMeters() function:" << std::endl;
        std::cout << "Value for X: " << X.toMeters()
                  << "m, and Y: " << Y.toMeters() << "m" << std::endl;

        units s( 9, 9, 9 );
        units k( 5, 5, 5 );
        std::cout << "onlyLittle() function with 9 heaps 9 lots and 9 littles "
                     "should be equal to 1521: "
                  << s.onlyLittle( 9, 9, 9 ) << std::endl;

        s.resetUnits( s.onlyLittle( 9, 9, 9 ) );
        std::cout
            << "resetUnits() function with 9 heaps 9 lots and 9 littles should "
               "be 9 heaps 10 lots 2 littles: "
            << static_cast<std::string>( s ) << std::endl;

        s.reInitialize( k );
        std::cout << "reInitialize() function with 9 heaps 9 lots and 9 "
                     "littles changing into 5 heaps 5 lots 5 littles: "
                  << static_cast<std::string>( s ) << std::endl;

        units m( 1, 2, 3 );
        std::cout << std::endl << "Getters: " << std::endl;
        std::cout << "getLittle() function littles = 1: " << m.getLittle()
                  << std::endl;
        std::cout << "getLot() function lots = 2: " << m.getLot() << std::endl;
        std::cout << "getHeap() function heaps = 3: " << m.getHeap()
                  << std::endl;

        std::cout << std::endl << "Setters: " << std::endl;
        m.setLittle( 3 );
        std::cout << "setLittle() function littles = 1, changing littles to 3: "
                  << static_cast<std::string>( m ) << std::endl;
        m.setLot( 6 );
        std::cout << "setLot() function lots = 2, changing lots to 6: "
                  << static_cast<std::string>( m ) << std::endl;
        m.setHeap( 12 );
        std::cout << "setHeap() function heaps = 3, changing heaps to 12: "
                  << static_cast<std::string>( m ) << std::endl;

        std::cout << std::endl << "Overloaded Operators:" << std::endl;

        ( X + Y );
        std::cout << "Addition operation (x + y) = "
                  << static_cast<std::string>( X ) << std::endl;
        X.reInitialize( R );
        ( X - Y );
        std::cout << "Subtraction operation (x - y) = "
                  << static_cast<std::string>( X ) << std::endl;
        X.reInitialize( R );
        ( X * Y );
        std::cout << "Multiplication operation (x * y) = "
                  << static_cast<std::string>( X ) << std::endl;
        X.reInitialize( R );
        ( X / Y );
        std::cout << "Division operation (x / y) = "
                  << static_cast<std::string>( X ) << std::endl;
        if ( X == Y )
        {
            std::cout << "Comparison operation (x == y) = true" << std::endl;
        }
        else
            std::cout << "Comparison operation (x == y) = false" << std::endl;

        // Do all operations
    }
}

// Functions to test the member functions

// getValue()
// toMeters()
// Getters
// Setters
