#include "deck.h"
#include "exception.h"
#include "player.h"
#include <iostream>
//#include <string>

int main()
{
    srand( time( 0 ) ); // random seed
    // creation of the deck
    deck p;
    // split the deck into a player deck and opponent deck
    deck s( p.split() );
    // instantiate the players half decks
    player p1( p );
    player p2( s );
    // instantiate the player hands
    sidePile sidepile1;
    //sidePile sidepile2;

    // Issues: goes on infinitely?
    // ===FIXED===!
    //
    // I also changed method in player sidepile remaining() to just return
    // ===YES==!
    // this->top
    //
    //
    // game loop
    std::cout << "Welcome to War\n";
    while ( true )
    {
        // initialize all the potential card pointers
        // THIS is fucking pointless
        // if i didn't have a fucking constructor that already did this
        // the default would handle it
        card* temp                 = nullptr;
        card* enemyPlayCard        = nullptr;
        card* side_pile_card       = nullptr;
        //card* enemy_side_pile_card = nullptr;
        card* cardPlayfromDeck     = nullptr;

        // condition for game end
        // player lost
        if ( p1.hand.isEmpty() )
        {
            std::cout << "Game over, you lost!\n";

            break;
        }
        else if ( p2.hand.isEmpty() )
        {
            std::cout << "Game over, you won!\n";

            break;
        }

        int choice;
        int choice2;
        // instantiate the drawn cards for both players

        temp          = p1.hand.draw();
        enemyPlayCard = p2.hand.draw();

        while ( true )
        {
            // std::cout
            //     << "\nYou drew a card, would you like to peek or play it(1 "
            //        "for peek,2 for play)\n";

            std::cout << "\tYou draw: " << temp->face << std::endl
                      << "[1] - Sidepile options\t [2] - Play it" << std::endl
                      << "Selection: ";
            std::cin >> choice;
            std::cout << std::endl;
            // the player wanted to peek
            if ( choice == 1 )
            {

                // the player wants to grab from sidepile
                std::cout << "\tSidepile options" << std::endl;
                // std::cout
                //     << "Do you want to pull a card out of the sidepile or "
                //        "push a card onto sidepile? (1 for pop,2 for push)\n";
                std::cout << "[1] - Draw\t [2] - Add" << std::endl
                          << "Selection: ";
                std::cin >> choice2;
                std::cout << std::endl;
                if ( choice2 == 1 )
                {
                    try
                    {
                        side_pile_card       = sidepile1.pop();
                        //enemy_side_pile_card = sidepile2.pop();

                        // since the user got a card from side pile, they
                        // must play both side_pile_card and temp card

                        if ( side_pile_card->value + temp->value >
                             enemyPlayCard->value )
                        {

                            std::cout << "You played: " << temp->face << " and "
                                      << side_pile_card->face << "\n";
                            std::cout
                                << "Opponent played: " << enemyPlayCard->face
                                << "\n";
                            std::cout << "You won\n";
                            // player one should now get the cards into his
                            // deck
                            p1.hand.returnToDeck( enemyPlayCard );
                            p1.hand.returnToDeck( side_pile_card );
                            p1.hand.returnToDeck( temp );
                        }
                        // player lost round
                        else
                        {
                            std::cout << "You played: " << temp->face << " and "
                                      << side_pile_card->face << "\n";
                            // YOU FORGOT TO PRINT BOTH ENEMY CARDS
                            std::cout
                                << "Opponent played: " << enemyPlayCard->face
                                << "\n";
                            std::cout << "You lost\n";
                            p2.hand.returnToDeck( enemyPlayCard );
                            p2.hand.returnToDeck( side_pile_card );
                            p2.hand.returnToDeck( temp );
                        }
                        break;
                    }
                    catch ( stackUnderflow e )
                    {
                        std::cerr << std::endl;
                        std::cerr << e.msg << std::endl;
                        std::cerr << "Side pile empty push a card before pop!"
                                  << std::endl;
                        std::cerr << std::endl;
                    }
                }

                // the player wants to push a card onto the sidepile
                else if ( choice2 == 2 )
                {
                    try
                    {
                        sidepile1.push( temp );

                        // since the player pushed onto sidepile, must play
                        // from deck
                        cardPlayfromDeck = p1.hand.draw();
                        //enemyPlayCard    = p2.hand.draw();
                        if ( cardPlayfromDeck->value > enemyPlayCard->value )
                        {
                            std::cout
                                << "You played: " << cardPlayfromDeck->face
                                << "\n";
                            std::cout
                                << "Opponent played: " << enemyPlayCard->face
                                << "\n";
                            std::cout << "You win\n";
                            // player wins so the card goes into player deck
                            p1.hand.returnToDeck( enemyPlayCard );
                            p1.hand.returnToDeck( cardPlayfromDeck );
                        }
                        // player lost
                        else
                        {
                            std::cout
                                << "You played: " << cardPlayfromDeck->face
                                << "\n";
                            std::cout
                                << "Opponent played: " << enemyPlayCard->face
                                << "\n";
                            std::cout << "you lost\n";
                            // player loses so cards go into enemy deck
                            p2.hand.returnToDeck( enemyPlayCard );
                            p2.hand.returnToDeck( cardPlayfromDeck );
                        }
                        break;
                    }
                    catch ( stackOverflow e )
                    {
                        std::cerr << std::endl;
                        std::cerr << e.msg << std::endl;
                        std::cerr << "Stack is full pop before pushing!"
                                  << std::endl;
                        std::cerr << std::endl;
                    }
                }
            }
            // the player did not want to peek
            else if ( choice == 2 )
            {
                // compare temp vs enemyPlayCard to see who won
                // player won
                if ( temp->value > enemyPlayCard->value )
                {
                    std::cout << "You played: " << temp->face << "\n";
                    std::cout << "Opponent played: " << enemyPlayCard->face
                              << "\n";
                    std::cout << "you won\n";
                    // return cards to player deck
                    //
                    p1.hand.returnToDeck( temp );
                    p1.hand.returnToDeck( enemyPlayCard );

                    // prints for debugging make sure cards dont get deleted
                    std::cout
                        << "Your deck size: " << p1.hand.size()
                        << ", and sidepile size: " << sidepile1.remaining()
                        << std::endl;
                    std::cout
                        << "computer deck size: " << p2.hand.size()
                        //<< ", and sidepile size: " << sidepile2.remaining()
                        << std::endl;
                }
                // opponent won
                else
                {
                    std::cout << "You played: " << temp->face << "\n";
                    std::cout << "Opponent played: " << enemyPlayCard->face
                              << "\n";
                    std::cout << "you lost\n";

                    p2.hand.returnToDeck( temp );
                    p2.hand.returnToDeck( enemyPlayCard );

                    // prints for debugging make sure cards dont get deleted
                    std::cout
                        << "Your deck size: " << p1.hand.size()
                        << ", and sidepile size: " << sidepile1.remaining()
                        << std::endl;
                    std::cout
                        << "computer deck size: " << p2.hand.size()
                        //<< ", and sidepile size: " << sidepile2.remaining()
                        << std::endl;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}
