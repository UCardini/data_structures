#include "deck.h"
#include "exception.h"
#include "player.h"
#include <iostream>
#include <string>

int main()
{
    deck p; 
    deck s(p.split());
    player p1(p);
    player p2(s);


    p1.hand.printLeftInDeck();
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    p2.hand.printLeftInDeck();

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::string f1 = p1.hand.peek().face;
    std::string f2 = p2.hand.peek().face;

    std::cout<<"face value for card1: "<<f1<<std::endl;

    std::cout<<"face value for card2: "<<f2<<std::endl;
    return 0;
}
