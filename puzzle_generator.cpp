//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "puzzle_generator.h"
std::ofstream fout;
std::ifstream fin;
PuzzleGenerator::PuzzleGenerator()
{

}

// Creates the word search board, fills it with the words from the user, fills the empty spaces with random letters,
// and outputs the board and key to the user.
void PuzzleGenerator::createWordSearch()
{
    srand(time(0));
    int maxRows, maxCols;
    char wordSearchLetters[1000][1000];
    std::string fileName, word;
    userOutput("How many words will be in the word search?");
    userInputNum(wordCount);

    createEmptyPuzzle(wordCount, maxRows, maxCols, wordSearchLetters);

    openFile(fout, "Words");
    userOutput("Enter the words you want in the word search:");
    for(int i = 0; i < wordCount; i++)
    {
        userInputWord(word);
        wordKey(fout, fileName, word);
        fillWordSearch(fin, maxRows, maxCols, wordSearchLetters, word);
    }
    closeFile(fout);

    outputWordSearch(fin, maxRows, maxCols,  wordSearchLetters);
    outputKey(fin);
    saveWordSearch(fout, fin, maxRows, maxCols, wordSearchLetters);
}

// Creates an empty word search board and then fills it with capitalized letters.
void PuzzleGenerator::createEmptyPuzzle(int& wordCount, int &maxRows, int &maxCols, char wordSearchLetters[][1000])
{
    maxRows = 10;
    maxCols = 10;

    if(wordCount > 5)
    {
        maxRows = wordCount * 2;
        maxCols = wordCount * 2;
    }

    for(int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            wordSearchLetters[i][j] = static_cast<char>(rand()%26+65);
        }
    }
}

// Opens a file named "Words" and writes all the words inputted by the user. The first letter is capitalized while the
// rest is lowercase
void PuzzleGenerator::wordKey(std::ofstream& out, std::string& fileName, std::string& word)
{
    out << static_cast<char>(toupper(word[0]));
    for(int i = 1; i < word.length(); i++)
    {
        out << static_cast<char>(tolower(word[i]));
    }
    out << std::endl;
}

// Fills the word search with words from the user
void PuzzleGenerator::fillWordSearch(std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000], std::string& word)
{
    srand(time(0));
    int randRow(0), randCol(0), wordLength, incrementRow, incrementCol;
    bool wordAdded = false;

    do
    {
        randomSpot(maxRows, maxCols, randRow, randCol, wordSearchLetters);
        wordLength = word.length();

        do
        {
            incrementRow = rand()%3 - 1;
            incrementCol = rand()%3 - 1;
        } while (incrementRow == 0 && incrementCol == 0);

        if (possibleDirectionCheck(maxRows, maxCols, randRow, randCol, incrementRow, incrementCol,
                                   wordSearchLetters, wordLength, word))
        {
            writeWord(randRow, randCol, incrementRow,incrementCol, wordSearchLetters, wordLength, word);
            wordAdded = true;
        }
    } while(wordAdded == false);
}

// Picks a random spot in the word search for a word added by the user to go
void PuzzleGenerator::randomSpot(int maxRows, int maxCols, int &randRow, int &randCol, char wordSearchLetters[][1000])
{
    do
    {
        randRow = rand()%maxRows;
        randCol = rand()%maxCols;
    } while (islower(wordSearchLetters[randRow][randCol]));
}

// Checks whether a direction(horizontal, diagonal, vertical) is possible for a word to be added in the word search
bool PuzzleGenerator::possibleDirectionCheck(int maxRows, int maxCols, int randRow, int randCol, int incrementRow, int incrementCol,
                            char wordSearchLetters[][1000], int wordLength, std::string& word)
{
    for(int i=0; i < wordLength; i++)
    {
        if((islower(wordSearchLetters[randRow][randCol])) && (wordSearchLetters[randRow][randCol] != word[i]))
            return false;
        else if((randRow < 0) || (randRow >= maxRows))
            return false;
        else if((randCol < 0) || (randCol >= maxCols))
            return false;
        else
        {
            randRow = randRow + incrementRow;
            randCol = randCol + incrementCol;
        }
    }
    return true;
}

// Fills the word search with word from the user
void PuzzleGenerator::writeWord(int randRow, int randCol, int incrementRow, int incrementCol, char wordSearchLetters[][1000],
               int& wordLength, std::string& word)
{
    for(int i = 0; i < wordLength; i++)
    {
        wordSearchLetters[randRow][randCol] = tolower(word[i]);
        randRow = randRow + incrementRow;
        randCol = randCol + incrementCol;
    }
}

// Outputs the word search board to the user by making all the letters lowercase
void PuzzleGenerator::outputWordSearch(std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000])
{
    for(int j = 0; j < maxRows; j++)
    {
        for(int x = 0; x < maxCols; x++)
        {
            std::cout.width(2);
            std::cout << static_cast<char>(tolower(wordSearchLetters[j][x]));
        }
        std::cout << std::endl;
    }
}

// Outputs the word search key
void PuzzleGenerator::outputKey(std::ifstream& in)
{
    char symbol;

    openFile(in,"Words");
    while(!in.eof())
    {
        fin.get(symbol);
        std::cout << symbol;
    }
    closeFile(in);
}

// Saves the word search by opening a file named by the user and writing everything in the file
void PuzzleGenerator::saveWordSearch(std::ofstream& out, std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000])
{
    char save, symbol;
    std::string fileName;

    userOutput("Would you like to save your word search? Y/N.");
    std::cin >> save;
    if(save == 'Y' || save == 'y')
    {
        userOutput("What would you like to name your word search?");
        std::cin >> fileName;

        openFile(out, fileName);
        for(int j = 0; j < maxRows; j++)
        {
            for(int x = 0; x < maxCols; x++)
            {
                out.width(2);
                out << static_cast<char>(tolower(wordSearchLetters[j][x]));
            }
            out << std::endl;
        }

        openFile(in, "Words");
        while(!in.eof())
        {
            fin.get(symbol);
            while(!isspace(symbol) && symbol != in.eof())
            {
                out << symbol;
                fin.get(symbol);
            }
            out << std::endl;
        }
        closeFile(out);
        closeFile(in);

        userOutput("Word search saved.");

        for(int j = 0; j < maxRows; j++)
        {
            for(int x = 0; x < maxCols; x++)
            {
                wordSearchLetters[j][x] = 0;
            }
        }
    }
}

// Outputs a message to the user
void PuzzleGenerator::userOutput(std::string message)
{
    std::cout << message << std::endl;
}

// Gets input of type int from the user
void PuzzleGenerator::userInputNum(int &input)
{
    std::cin >> input;
}

// Gets input of type string from the user
void PuzzleGenerator::userInputWord(std::string &word)
{
    std::cin >> word;
}

// Opens file of type ofstream
void PuzzleGenerator::openFile(std::ofstream& out, std::string fileName)
{
    out.open(fileName);
    if (out.fail())
    {
        userOutput("Could not open file of type ofstream.");
        exit(1);
    }
}

// Opens file of type ifstream
void PuzzleGenerator::openFile(std::ifstream& in, std::string fileName)
{
    in.open(fileName);
    if (in.fail())
    {
        userOutput("Could not open file of type ifstream.");
        exit(2);
    }
}

// Closes file of type ofstream
void PuzzleGenerator::closeFile(std::ofstream& out)
{
    out.close();
}

// Closes file of type instream
void PuzzleGenerator::closeFile(std::ifstream& in)
{
    in.close();
}