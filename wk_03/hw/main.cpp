#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct library
{
    string title;
    string author;
    int wordCount; // How many words are present a word is at least 2 letters 
    double letterFrequency[26]; // How many times each letter has occurred
    int lineCount; // How many new lines are in the contents
};

void wordCounter(string currentLine, int& wordCount);
void letterCounter(string word, int letterCount[], int& totalLetters);
ifstream fileOpen();

int main()
{
    bool processBook = true;
    while (processBook)
    {
        library book;
        ifstream data{ fileOpen() };
        fstream dataStore("CardCatalog.txt", ios::app);
        dataStore.seekp(0, ios::beg);
        string inFile{};

        string word;
        int totalLetters = 0;
        int letterCount[26];
        int wordCount = 0;
        string line;
        char selection = 'n';
        char alphebetL[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

        for (int k{}; k < 26; k++) letterCount[k] = 0; // initialize all values in letterCount to 0 

        data >> inFile;
        data >> word; book.title = inFile + " " + word; // Finding title
        data >> inFile;
        data >> word; book.author = inFile + " " + word;

        getline(data, inFile);
        
        book.lineCount = 0;
        while (getline(data, inFile))
        {
            if (!(inFile.empty() || inFile == "Contents: " || inFile == "Contents:")) {
                book.lineCount++;
                letterCounter(inFile, letterCount,totalLetters);
                wordCounter(inFile, wordCount);
            }
        }
        

        
        book.wordCount = wordCount+book.lineCount+1;//add number of lines to account for new lines
                                                    //also add one to account for last word
        dataStore << "Title: " << book.title << "\n\n";
        dataStore << "Full Author: " << book.author << "\n\n";
        dataStore << "Author First Name: ";
        for (int c = 0; c < book.author.length(); c++)
        {
            if (book.author[c] != ' ')
            {
                dataStore << book.author[c];
            }
            else
            {
                c++;
                dataStore << "\n\n" << "Author Last Name: " << book.author[c];
            }
        }
        dataStore << "\n\n" << "Word count: " << book.wordCount << "\n\n";
        dataStore << "Line count: " << book.lineCount << "\n\n";
        dataStore << "|-----------------------------|\n\n";

        for (int k = 0; k < 26; k++)
        {
            book.letterFrequency[k] = static_cast<double>(letterCount[k]) / totalLetters;
            
        }

        cout << "View letter frequency? (y/n): ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
            cout << book.title << " letter frequency: " << endl;
            for (int i = 0; i < 26; i++)
            {
                cout << alphebetL[i] << ": " << book.letterFrequency[i] << endl;
            }
        }

        cout << "Would you like to process another book?: (y/n): ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
            processBook = true;
        }
        else
        {
            processBook = false;
        }
    }
    return 0;
}

ifstream fileOpen()
{
    ifstream data;
    string file{};

    cout << "Please enter a file name: ";
    cin >> file;
    data.open(file, ios::in);
    while (data.fail())
    {
        cout << "ERROR - Failed to open file named: " << file << ".\n Please enter another file: ";
        cin >> file;
        data.open(file, ios::in);
    }
    return data;
}

void letterCounter(string word, int letterCount[], int& totalLetters)
{
    char alphabetL[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char alphabetC[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };


    int wordIndex = word.length();
    for (int j{}; j < wordIndex; j++)
    {
        for (int k{}; k < 26; k++)
        {
            if (word[j] == alphabetL[k] || word[j] == alphabetC[k])
            {
                letterCount[k] += 1;
                totalLetters += 1;
            }
        }
    }
}

void wordCounter(string currentLine, int& wordCount)
{
    int lineLength = currentLine.length();
    for (int i = 0; i < lineLength; i++) {
        if ((currentLine[i] == ' ')) {
            wordCount++;
        }
    }
    
}
