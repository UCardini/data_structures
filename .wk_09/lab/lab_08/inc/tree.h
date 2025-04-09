#ifndef TREE_H // Is this better than pragma
#define TREE_H

#include "node.h"
#include "wordCounts.h"

template <typename T> class tree
{
public:
    node<T>* root; // Should be ptr?
                   // YES

    tree() { this->root = nullptr; }

    ~tree()
    // recursive emptyTree function :)
    {
        delete this->root;
        this->root = nullptr;
    }

private:
    // Helpers and overloaded
    node<T>* insert( node<T>*, T );
    node<T>* find( node<T>*, T );
    node<T>* balance( node<T>* );
    node<T>* remove( node<T>*, T );
    int size( node<T>* );

    // Yes I overloaded this function 3 times
    // I already wrote node** gAA(int) as my public
    // function inside of here as node** gAA() I cant be
    // bothered to fix the void function so bite me
    //
    // used g++ instead of clang++ and fixed everything
    //
    void getAllAscending( node<T>*, node<T>**, int& );
    void getAllDescending( node<T>*, node<T>**, int& );
    // node<T>** getAllAscending( int );
    // node<T>** getAllDescending( int );

    node<T>* largest( node<T>* );
    node<T>* lowest( node<T>* );
    bool isRoot( node<T>* );
    node<T>* rotateLeft( node<T>* );
    node<T>* rotateRight( node<T>* );
    node<T>* rotateRightLeft( node<T>* );
    node<T>* rotateLeftRight( node<T>* );

public:
    // public functions to use in main

    void insert( T inVal ) { insert( this->root, inVal ); }

    node<T>* find( T inVal ) { return find( this->root, inVal ); }

    int height( node<T>* );

    int height() { return height( this->root ); }

    int balanceFactor( node<T>* );

    node<T>* remove( T inVal ) { return remove( this->root, inVal ); }

    int size() { return size( this->root ); }

    node<T>** getAllAscending(); // //{ return getAllAscending(  ); };

    node<T>** getAllDescending(); // { return getAllDescending(  ); };

    // this recursively deletes nodes
    // take my word for it wor see for yourself
    void emptyTree() { this->~tree(); }
};
// breaks without this I refuse to use .tpp file extension or
// separate header file for implementation
template class tree<wordCount>;
#endif // !TREE_H
