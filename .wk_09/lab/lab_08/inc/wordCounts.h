#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>

class wordCount
{
public:
    std::string word;
    int count;

private:
    // needed to make printing the balanceFactor and height
    // work better
    int height;
    int balanceFactor;
    bool bsdOther; // this name literally means nothing lmfao

public:
    wordCount( const std::string word )
    {
        this->word     = word;
        this->count    = 1;
        this->bsdOther = false;
    }

    void adjustHeightBalance( int height, int balanceFactor )
    {
        this->height        = height;
        this->balanceFactor = balanceFactor;
        this->bsdOther      = true;
    }

    // Overloaded operators
    // required to make tree work
    // comparing right side as a string instead of obj would be ideal
    bool operator==( const wordCount right ) const
    {
        return this->word == right.word;
    }

    bool operator<( const wordCount right ) const
    {
        return this->word < right.word;
    }

    bool operator>( const wordCount right ) const
    {
        return this->word > right.word;
    }

    bool operator<=( const wordCount right ) const
    {
        return this->word <= right.word;
    }

    bool operator>=( const wordCount right ) const
    {
        return this->word >= right.word;
    }

    void operator+( const std::string right )
    {
        if ( this->word == right )
        {
            this->count++;
        }
    }

    friend std::ostream& operator<<( std::ostream& os, wordCount wc )
    {
        if ( wc.bsdOther )
        {
            wc.bsdOther = false;
            return os << "{" << wc.word << "=" << wc.count << " H=" << wc.height
                      << " BF=" << wc.balanceFactor << "}";
        }
        return os << wc.word << "=" << wc.count;
    }
};
#endif // !WORDCOUNT_H
