#include "linkedList.h"
#include <iostream>

int main()
{
    deck p;

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

    // while ( !p.isEmpty() )
    // {
    //     p.printLeftInDeck();
    //     p.draw();
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }
    // p.isEmpty();

    return 0;
}
