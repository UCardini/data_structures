#include "tree.h"
#include <fstream>
#include <iostream>
#include <string>

// needs declared here and placed at end
struct library
{
    std::string title;
    std::string author;
    int wordCount = 0;
    int lineCount = 0; // How many new lines are in the contents

    void deleteLibrary()
    {
        this->title     = "";
        this->author    = "";
        this->wordCount = 0;
        this->lineCount = 0;
    }
};

// Function declarations
std::string getData( std::string, library& );
std::string cleanData( std::string );
bool outputOpts();
void fileOutput( std::fstream&, library, bool );

int main()
{
    library book;
    bool viewInFile   = outputOpts();
    bool choosingFile = true;

    while ( choosingFile )
    {
        std::fstream outputData( "data/output/CardCatalog.txt", std::ios::app );
        std::string file;
        std::cout << "Please enter a file name: ";
        std::cin >> file;
        std::cout << std::endl;

        std::string fromFile = getData( file, book );
        fromFile             = cleanData( fromFile );
        tree<wordCount> wordTree;
        int k = 0;
        for ( int i = 0; i < fromFile.length(); i++ )
        // insert words into tree
        {
            if ( fromFile[ i ] == ' ' )
            {
                std::string word = "";
                for ( ; k < i; k++ )
                {
                    word += fromFile[ k ];
                }
                k = i + 1;

                if ( word == "" )
                // just in case theres an empty val
                // which there is in peterpan for some reason
                // could check when cleaning this is the
                // first place I put it
                {
                    continue;
                }

                book.wordCount++;
                node<wordCount>* found = wordTree.find( wordCount( word ) );
                if ( found == nullptr )
                {
                    wordTree.insert( wordCount( word ) );
                }
                else
                {
                    found->data + word;
                }
            }
        }

        fileOutput( outputData, book, viewInFile );
        bool processingFile = true;
        while ( processingFile )
        {
            std::string choice;
            std::cout << "Options:" << std::endl;
            std::cout << "[1] - Search for a word" << std::endl;
            std::cout << "[2] - View words and counts in Ascending order"
                      << std::endl;
            std::cout << "[3] - View words and counts in Descending order"
                      << std::endl;
            std::cout << "[4] - View size of tree" << std::endl;
            std::cout << "[5] - Remove a word" << std::endl;
            std::cout << "[6] - Empty tree" << std::endl;
            std::cout << "[7] - Letter frequency" << std::endl;
            std::cout << "[8] - Word frequency" << std::endl;

            std::cout << "[9] - Enter new file" << std::endl;
            std::cout << "[0] - Exit" << std::endl;
            std::cout << std::endl << "Enter your selection: ";

            std::cin >> choice;
            std::cout << std::endl;

            if ( choice == "1" )
            // search
            //
            // find value in tree
            {
                std::string word;
                std::cout << std::endl;
                std::cout << "Enter word to search: ";
                std::cin >> word;
                std::cout << std::endl;
                word = cleanData( word );

                node<wordCount>* found = wordTree.find( wordCount( word ) );
                if ( viewInFile )
                {
                    outputData << "Search for word:" << std::endl;
                }
                if ( found == nullptr )
                {
                    std::cout << word << " NOT found in tree!" << std::endl;
                    if ( viewInFile )
                    {
                        outputData << "\t" << word << " NOT found in tree!"
                                   << std::endl;
                    }
                }
                else
                {
                    std::cout << found->data << std::endl;
                    if ( viewInFile )
                    {
                        outputData << "\t" << found->data << std::endl;
                    }
                }
            }
            else if ( choice == "2" )
            // ascending ordered array
            //
            // all values in tree returned in order as a array of pointers
            // values are printed out and their corresponding heights and
            // balance factors are as well
            {
                node<wordCount>** arr = wordTree.getAllAscending();
                for ( int i = 0; i < wordTree.size(); i++ )
                {
                    // whoops made my bed time to sleep in it
                    // these are obviously calculated when making the
                    // array however i wanted to add an option to include
                    // it in the file
                    int height        = wordTree.height( arr[ i ] );
                    int balanceFactor = wordTree.balanceFactor( arr[ i ] );
                    arr[ i ]->data.adjustHeightBalance( height, balanceFactor );
                    std::cout << arr[ i ]->data << " ";

                    if ( viewInFile )
                    {
                        if ( i == 0 )
                        {
                            outputData << "Ordered Ascending list:";
                        }
                        if ( i % 5 == 0 )
                        {
                            outputData << std::endl << "\t";
                        }
                        outputData << arr[ i ]->data << " ";
                        if ( i + 1 == wordTree.size() )
                        {
                            outputData << std::endl;
                        }
                    }
                }
                std::cout << std::endl;
                delete[] arr;
            }
            else if ( choice == "3" )
            // descending ordered array
            //
            // all values in tree returned in order as a array of pointers
            // values are printed out and their corresponding heights and
            // balance factors are as well
            {
                node<wordCount>** arr = wordTree.getAllDescending();
                for ( int i = 0; i < wordTree.size(); i++ )
                {
                    // whoops made my bed time to sleep in it
                    // these are obviously calculated when making the
                    // array however i wanted to add an option to include
                    // it in the file
                    int height        = wordTree.height( arr[ i ] );
                    int balanceFactor = wordTree.balanceFactor( arr[ i ] );
                    arr[ i ]->data.adjustHeightBalance( height, balanceFactor );
                    std::cout << arr[ i ]->data << " ";
                    if ( viewInFile )
                    {
                        if ( i == 0 )
                        {
                            outputData << "Ordered Descending list:";
                        }
                        if ( i % 5 == 0 )
                        {
                            outputData << std::endl << "\t";
                        }
                        outputData << arr[ i ]->data << " ";
                        if ( i + 1 == wordTree.size() )
                        {
                            outputData << std::endl;
                        }
                    }
                }
                std::cout << std::endl;
                delete[] arr;
            }
            else if ( choice == "4" )
            // size
            {
                int size = wordTree.size();
                std::cout << "Number of unique words in book: " << size;
                std::cout << std::endl;
                if ( viewInFile )
                {
                    outputData << "Size of tree:" << std::endl;
                    outputData << "\t# of Unique words in book: " << size;
                    outputData << std::endl;
                }
            }
            else if ( choice == "5" )
            // remove
            //
            // finds word in tree if null it's not found
            // if found it removes it. could make remove function
            // return the item instead to make more efficent
            {
                std::string word;
                std::cout << std::endl;
                std::cout << "Enter a word to remove from the tree: ";
                std::cin >> word;
                std::cout << std::endl;
                word = cleanData( word ); 

                node<wordCount>* found = wordTree.find( wordCount( word ) );
                if ( found == nullptr )
                {
                    std::cout << word << " NOT found in tree!" << std::endl;
                    if ( viewInFile )
                    {
                        outputData << "Word to remove:" << std::endl << "\t";
                        outputData << word << " Not Found in Tree!"
                                   << std::endl;
                    }
                }
                else
                {
                    std::cout << found->data << " [REMOVED]" << std::endl;
                    if ( viewInFile )
                    {
                        outputData << "Word to remove:" << std::endl << "\t";
                        outputData << found->data << " [REMOVED]" << std::endl;
                    }
                }
                wordTree.remove( wordCount( word ) );
            }
            else if ( choice == "6" )
            // empty tree
            {
                wordTree.emptyTree();
                std::cout << "Tree is now empty!" << std::endl;
                std::cout << "You can:" << std::endl;
                std::cout << "[1] - Exit now" << std::endl;
                std::cout << "[2] - Choose file to process" << std::endl;
                std::cout << "[3] - Continue testing empty tree" << std::endl;
                std::cin >> choice;
                std::cout << std::endl;

                if ( viewInFile )
                {
                    outputData << "Empty Tree:" << std::endl << "\t";
                    outputData << "Tree is now empty" << std::endl;
                }

                if ( choice == "1" )
                {
                    choosingFile   = false;
                    processingFile = false;
                }
                else if ( choice == "2" )
                {
                    processingFile = false;
                }
                else if ( choice == "3" )
                {
                    continue;
                }
            }
            else if ( choice == "7" )
            // letter frequency
            //
            // have to calculate # of letters in each of the words
            // in the tree more efficent the going through the entire
            // string again
            {
                tree<wordCount> letterTree;
                // this really should be a pointer to first node in
                // a list instead of pointer to first pointer in list
                node<wordCount>** arr = wordTree.getAllAscending();
                std::string character = ""; // wont let me use '' obviously
                for ( int i = 0; i < wordTree.size(); i++ )
                {
                    for ( int k = 0; k < arr[ i ]->data.word.length(); k++ )
                    {
                        character = arr[ i ]->data.word[ k ];
                        node<wordCount>* found =
                            letterTree.find( wordCount( character ) );

                        if ( found == nullptr )
                        {
                            letterTree.insert( wordCount( character ) );
                        }
                        else
                        // add the count to the occurances of the letter found
                        // to the letterTree
                        {
                            found->data.count += arr[ i ]->data.count;
                        }
                    }
                }
                delete[] arr; // idk if this is necissary

                node<wordCount>** arr_letters = letterTree.getAllAscending();
                int totalLetters              = 0;
                for ( int i = 0; i < letterTree.size(); i++ )
                {
                    totalLetters += arr_letters[ i ]->data.count;
                }

                if ( viewInFile )
                {
                    outputData << "Letter Frequencies:" << std::endl;
                }

                double frequency;
                for ( int i = 0; i < letterTree.size(); i++ )
                // I dont like wanna use std::round() so I intentionally
                // eat the data loss
                {
                    frequency = ( arr_letters[ i ]->data.count * 10000 /
                                  totalLetters ) /
                                static_cast<double>( 10000 );
                    std::cout << arr_letters[ i ]->data
                              << " Frequency=" << frequency << std::endl;
                    if ( viewInFile )
                    {
                        outputData << "\t" << arr_letters[ i ]->data
                                   << " Frequency=" << frequency << std::endl;
                    }
                }
                delete[] arr_letters;
            }
            else if ( choice == "8" )
            // word frequency
            {
                node<wordCount>** arr = wordTree.getAllAscending();

                if ( viewInFile )
                {
                    outputData << "Word Frequencies:" << std::endl;
                }
                double frequency;
                for ( int i = 0; i < wordTree.size(); i++ )
                {
                    frequency =
                        ( arr[ i ]->data.count * 10000 / book.wordCount ) /
                        static_cast<double>( 10000 );
                    std::cout << arr[ i ]->data << " Frequency=" << frequency
                              << std::endl;
                    if ( viewInFile )
                    {
                        outputData << "\t" << arr[ i ]->data
                                   << " Frequency=" << frequency << std::endl;
                    }
                }
                delete[] arr;
            }
            else if ( choice == "9" )
            // add another file
            {
                wordTree.emptyTree();
                processingFile = false;
            }
            else if ( choice == "0" )
            // exit
            {
                processingFile = false;
                choosingFile   = false;
                if ( viewInFile )
                {
                    outputData.close();
                }
            }
            if ( viewInFile )
            {
                outputData << std::endl;
            }
        }
    }
    return 0;
}

std::string getData( std::string file, library& book )
// returns all data after "Contents:" in file as a single string
// excluding blank lines and terminating chars
// scratched my head for too long trying to do this shoudlve
// just been lazy
{
    std::string contents, line;
    std::ifstream data( "data/input/" + file, std::ios::in );

    while ( data.fail() )
    {
        std::cerr << "[ERROR] - Failed to open file named: " << file << "."
                  << std::endl;
        std::cerr << "Please enter another file: ";
        std::cin >> file;
        data.open( "data/input/" + file, std::ios::in );
    }
    std::cout << std::endl;
    book.deleteLibrary(); // for if a book has already been processed

    getline( data, line );
    line.erase( line.length() - 1 );
    book.title = line; // get book title

    getline( data, line );
    line.erase( line.length() - 1 );
    book.author = line; // Get author name

    while ( getline( data, line ) )
    // theres hidden characters '\0', '\r', ' ', '\n'
    // because I wanted to return entire string to make it
    // usable i had to delete all terminating characters
    {
        if ( !line.empty() && ( line[ line.length() - 1 ] == ' ' ||
                                line[ line.length() - 1 ] == '\r' ||
                                line[ line.length() - 1 ] == '\n' ) )
        {

            line.erase( line.length() - 1 );
        }

        if ( line != "Contents:" && !line.empty() )
        // skips contents line
        {
            book.lineCount++;
            contents += line + ' ';
        }
    }
    data.close();
    return contents; // entire file contents excluding contents and empty lines
}

std::string cleanData( std::string data )
// standardizes all words in the data for processing
//  ex: Go-to = goto
{
    char alphabetL[ 26 ] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char alphabetC[ 26 ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                             'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    for ( int i = 0; i < data.length(); i++ )
    {
        for ( int k = 0; k < 26; k++ )
        {
            if ( data[ i ] == alphabetC[ k ] || data[ i ] == alphabetL[ k ] )
            {
                data[ i ] = alphabetL[ k ];
                break;
            }
            if ( k >= 25 && data[ i ] != ' ' ) //&& contents[ i ] != '-'
                                               // read as single word regardless
            {
                data.erase( i, 1 );
                i--;
            }
        }
    }
    return data;
}

bool outputOpts()
// allows for outputs to cardcatalog.txt for testing
{
    bool viewInFile;
    bool completePrompt = false;
    while ( !completePrompt )
    {
        std::string choice;
        std::cout << "How would you like to view the output data?" << std::endl;
        std::cout << "[1] - [Default] Terminal";
        std::cout << " (required info appends \"CardCatalog.txt\")"
                  << std::endl;

        std::cout << "[2] - Put data in \"CardCatalog.txt\"";
        std::cout << " (for testing)" << std::endl;

        std::cout << "Enter your selection: ";
        std::cin >> choice;
        std::cout << std::endl;

        if ( choice == "1" )
        {
            viewInFile     = false;
            completePrompt = true;
        }
        else if ( choice == "2" )
        {
            viewInFile     = true;
            completePrompt = true;
        }
    }
    return viewInFile;
}

void fileOutput( std::fstream& outputData, library book, bool viewInFile )
// called when a new book is entered give generic info
{
    outputData << "******************************NEW_"
                  "FILE******************************"
               << std::endl;
    outputData << "Title: " << book.title << std::endl;
    outputData << "Author: " << std::endl;
    outputData << "\tFull Name: " << book.author << std::endl;

    int k = 0;
    outputData << "\tFirst Name: ";
    for ( int i = 0; i < book.author.length(); i++ )
    // gets author first and last name on separate lines for
    // card catalog
    {
        if ( book.author[ i ] == ' ' )
        {
            for ( ; k < i; k++ )
            {
                outputData << book.author[ k ];
            }
            k = i + 1;
            if ( k != book.author.length() )
            {
                outputData << std::endl << "\tLast Name: ";
            }
        }
        else if ( k != 0 )
        {
            outputData << book.author[ i ];
        }
    }
    outputData << std::endl;
    outputData << "Word Count: " << book.wordCount << std::endl;
    outputData << "Line Count: " << book.lineCount << std::endl;
    outputData << std::endl;

    if ( !viewInFile )
    {
        outputData.close();
    }
}
