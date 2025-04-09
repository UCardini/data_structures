#ifndef HashTable_h
#define HashTable_h

#include "Student.h"
#include <cstddef>
#include <string>

using std::string;

template <typename T> class HashTable
{
private:
    int MAXSIZE;
    Student* Arr;

    int Hash( string& );

public:
    HashTable() : MAXSIZE( 100 ) { Arr = new Student[ 100 ]; }

    HashTable( int value ) : MAXSIZE( value ), Arr(new Student[MAXSIZE]) {}

    void AddItem( Student* );
    Student* RemoveItem(string&);

    int GetLength();
};

template <typename T>
int HashTable<T>::Hash( string& inval )
{
    int hash_value = 0;
    for ( auto& c : inval )
    {
        hash_value += int( c );
    }

    return hash_value %= MAXSIZE;
}

template <typename T>
void HashTable<T>::AddItem( Student* inval )
{
    //int hash_value = 0;
    int hash_value = Hash(inval->Mnumber);

    if ( &Arr[ hash_value ] == nullptr )
    {
        // Add Item, INVAL DEREFERENCED
        Arr[ hash_value ] = *inval;
    }
    else
    {
        while (&Arr[hash_value] != nullptr)
        {
            hash_value++;
        }

        Arr[hash_value] = *inval;
    }
}

template <typename T>
Student* HashTable<T>::RemoveItem(string& inval)
{
    int hash_value = Hash(inval);

    Student* temp = Arr[hash_value];

    Arr[hash_value] = nullptr;

    return temp;
}






#endif // !HashTable.h
