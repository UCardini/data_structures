#include "dataStructures.h"
#include "exception.h"
#include <fstream>
#include <iostream>
#include <string>

std::string inputStream( bool );
std::string reverseWord( std::string );
std::string reverseInput( std::string );
std::string wordPunctuation( std::string );

int main()
{
    bool isFile = false;
    while ( true )
    {
        std::string entry;
        std::cout << "Would you enter from (1=file or "
                     "2=terminal): ";
        std::cin >> entry;
        std::cout << std::endl;

        if ( entry == "1" || entry == "2" )
        {
            isFile = entry == "1";
            std::cin.ignore();
            break;
        }
        std::cerr << "[ERROR] - Invalid entry!" << std::endl;
    }
    std::string thangy = inputStream( isFile );
    std::string Q      = reverseInput( thangy );
    std::cout << Q << std::endl;

    return 0;
}

std::string inputStream( bool fromFile )
{
    std::ifstream file;
    std::string inVal = "";
    if ( fromFile )
    {
        while ( true )
        {
            std::string fileName;
            std::cout << "Enter the file name: ";
            std::getline( std::cin, fileName );
            std::cout << std::endl;
            file.open( fileName, std::ios::in );
            if ( !file.fail() )
            {
                std::string temp;
                std::getline( file, inVal );
                while ( std::getline( file, temp ) )
                {
                    inVal += " " + temp;
                }
                file.close();
                break;
            }
            std::cerr << "[ERROR] - File doesn't exist!" << std::endl;
        }
        return inVal;
    }
    std::cout << "Enter line of text to reverse: ";
    std::getline( std::cin, inVal );
    return inVal;
}

std::string reverseWord( std::string inVal )
{
    stack<char> S( inVal.length() );
    for ( int i = 0; i < inVal.length(); i++ )
    {
        try
        {
            S.push( &inVal[ i ] );
        }
        catch ( stackOverflow e )
        {
            std::cout << e.msg << std::endl;
        }
    }
    queue<char> Q( inVal.length() + 1 );
    std::string outVal;
    for ( int i = 0; i < inVal.length(); i++ )
    {
        try
        {
            Q.enqueue( S.pop() );
        }
        catch ( stackUnderflow e )
        {
            std::cout << e.msg << std::endl;
        }
        catch ( queueOverflow e )
        {
            std::cout << e.msg << std::endl;
        }
    }
    while ( !Q.isEmpty() )
    {
        char value = *Q.dequeue();
        if ( value == '(' )
        {
            outVal += ')';
        }
        else if ( value == ')' )
        {
            outVal += '(';
        }
        else if ( value == '[' )
        {
            outVal += ']';
        }
        else if ( value == ']' )
        {
            outVal += '[';
        }
        else if ( value == '{' )
        {
            outVal += '}';
        }
        else if ( value == '}' )
        {
            outVal += '{';
        }
        else
        {
            outVal += value;
        }
    }
    return wordPunctuation( outVal );
};

std::string reverseInput( std::string inVal )
{
    std::string outVal;
    int length = inVal.length();
    int k      = 0;
    for ( int i = 0; i < length; i++ )
    {
        std::string word;
        k++;
        if ( inVal[ i ] == ' ' )
        {
            for ( int j = i + 1 - k; j + 1 < i + 1; j++ )
            {
                word += inVal[ j ];
            }
            outVal += reverseWord( word );
            outVal += ' ';
            k = 0;
        }
    }
    if ( 0 < k )
    {
        k += 1;
        std::string lastWord;
        for ( int t = length - 1; length - k < t; t-- )
        {
            lastWord += inVal[ t ];
        }
        outVal += wordPunctuation( lastWord );
    }
    return outVal;
}

// Test case shows (This is a test. = sihT si a tset.)
// which has altered punctuation
std::string wordPunctuation( std::string inVal )
{
    std::string outVal;
    if ( inVal[ 0 ] == '.' || inVal[ 0 ] == ',' || inVal[ 0 ] == '!' ||
         inVal[ 0 ] == '?' || inVal[ 0 ] == ';' || inVal[ 0 ] == ':' )
    {
        for ( int i = 1; i < inVal.length(); ++i )
        {
            outVal += inVal[ i ];
        }
        return outVal + inVal[ 0 ];
    }
    outVal = inVal;
    return outVal;
}
