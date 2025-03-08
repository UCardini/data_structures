#include "deck.h"
#include "exception.h"
#include "player.h"
#include <iostream>

int main()
{

    /*
    p.printLeftInDeck();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    card* n = p.draw();
    std::cout << "Card: " << n->face << " removed from deck, size: " << p.size()
              << std::endl;
    p.printLeftInDeck();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    p.returnToDeck( n );
    std::cout << "Card: " << n->face << " returned to deck, size: " << p.size()
              << std::endl;
    p.printLeftInDeck();
    */

    // while ( !p.isEmpty() )
    // {
    //     p.printLeftInDeck();
    //     p.draw();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }
    // p.isEmpty();

    deck p;
    card x;
    sidePile pyle;
    try
    {
        pyle.push( p.draw() );
        pyle.push( p.draw() );
        pyle.push( p.draw() );
        pyle.push( p.draw() );
        pyle.push( p.draw() );

        std::cout << pyle.display( pyle.pop() ) << std::endl;
        std::cout << pyle.display( pyle.pop() ) << std::endl;
        std::cout << pyle.display( pyle.pop() ) << std::endl;
        std::cout << pyle.display( pyle.pop() ) << std::endl;
    }
    catch ( stackOverflow e )
    {
        std::cout << e.msg << std::endl;
    }
    catch ( stackUnderflow e )
    {
        std::cout << e.msg << std::endl;
    }

    return 0;
}
