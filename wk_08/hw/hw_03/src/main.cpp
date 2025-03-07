#include "linkedList.h"
#include <iostream>

int main()
{
    deck p;

    while ( !p.isEmpty() )
    {
        p.printLeftInDeck();
        p.draw();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    p.isEmpty();

    return 0;
}
