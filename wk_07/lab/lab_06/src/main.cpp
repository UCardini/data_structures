#include "dataStructures.h"
#include "exception.h"
#include <fstream>
#include <iostream>
#include <string>

std::string inputStream( bool );
queue<std::string> reverseString( std::string, int);
int countSpaces(std::string);
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
    std::string thangy=inputStream( isFile ); 
    //std::cout<<thangy<<std::endl;

    queue<std::string> final = reverseString(thangy, countSpaces(thangy)+1);
    std::cout<<"HIT"<<std::endl;

    while (!final.isEmpty())
    {
        std::cout<<*final.dequeue()<<std::endl;
    }

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

queue<std::string> reverseString(std::string inVal, int spaces) {
    std::string none = "";
    std::string* outVal= &none;
    queue<std::string> F(spaces);
    stack<char> M(inVal.length()); // Initialize stack with sufficient capacity
    int T = 0; // Word length counter

    for (int i = 0; i < inVal.length(); i++) {
        if (inVal[i] != ' ') {
            T++; // Increment word length counter
        } else {
            // Push characters of the current word onto the stack
            for (int j = i - T; j < i; j++) {
                M.push(&inVal[j]); // Push pointer to character
            }

            // Pop characters from the stack to reverse the word
            while (M.length() > 0) {
                outVal += *M.pop(); // Append popped character to outVal
            }
            F.enqueue(outVal);

            T = 0; // Reset word length counter
        }
    }

    // Handle the last word (if any)
    if (T > 0) {
        // Push characters of the last word onto the stack
        for (int j = inVal.length() - T; j < inVal.length(); j++) {
            M.push(&inVal[j]); // Push pointer to character
        }

        // Pop characters from the stack to reverse the word
        while (M.length() > 0) {
            outVal += *M.pop(); // Append popped character to outVal
        }
        F.enqueue(outVal);
    }

    return F;
}

int countSpaces(std::string inVal)
{
    int k = 0;
    for(int i = 0; i < inVal.length(); i++)
    {
        if (inVal[i] == ' ')
        {
            k++;
        }
    }
    return k;
}
