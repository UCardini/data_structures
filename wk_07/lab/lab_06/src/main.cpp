#include "dataStructures.h"
#include <iostream>

int main()
{
    stack<int> p( 5 );

    int* t = new int( 8 );
    int* q = new int( 5 );
    int* s = new int( 9 );
    p.push( t );
    p.push( q );
    p.push( s );

    int* k = p.pop();
    std::cout << *k << std::endl;
    std::cout << p.length() << std::endl;

    int* m = new int( 1 );
    int* r = new int( 12 );
    p.push( m );
    p.push( r );

    // int* f = p.pop();
    // std::cout << *f << std::endl;
    std::cout << p.length() << std::endl;

    int* x = new int( 12 );
    p.push( x );
    // p.push( m );
    // p.push( x );

    int* y = p.pop();
    std::cout << *y << std::endl;
    std::cout << p.length() << std::endl;

    p.empty();
    p.push( t );

    std::cout << p.length() << std::endl;
    return 0;
}
