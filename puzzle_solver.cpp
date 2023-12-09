//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "puzzle_solver.h"

// Initializes a new instance of PuzzleSolver class
PuzzleSolver::PuzzleSolver() {

}

// Solves the puzzle by opening the puzzle file, placing the letters of the word search in an array, finding the word
// in the word search and then creating a new array with only the words.
void PuzzleSolver::solvePuzzle(std::ifstream& in)
{
    int maxRows, maxCols;
    char wordSearch[1000][1000], wordSearchAnswers[1000][1000];
    char symbol;
    std::string word;

    userOutput("What puzzle would you like to solve?");
    userInputWord(fileName);

    openFile(in, fileName);
    in.get(symbol);
    for (int i = 0; !isupper(symbol); i++)
    {
        for(int j = 0; !isupper(symbol) && !in.eof() && symbol != '\n' ; j++)
        {
            if(symbol == ' ')
            {
                in.get(symbol);
            }
            wordSearch[i][j] = symbol;
            in.get(symbol);
            maxRows = i;
            maxCols = j;
        }
        in.get(symbol);
    }
    in.putback(symbol);

    maxRows = maxRows + 1;
    maxCols = maxCols + 1;

    for (int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            wordSearchAnswers[i][j] = ' ';
        }
    }

    while (in >> word)
    {
        findWord(word, maxRows, maxCols, wordSearch, wordSearchAnswers);
    }

    outputWordSearch(in, maxRows, maxCols, wordSearchAnswers);
    closeFile(in);
}

// Finds the word in the puzzle by finding the first letter and then checking the letters around it.
bool PuzzleSolver::findWord(std::string& word, int maxRows, int maxCols, char wordSearch[][1000], char wordSearchAnswers[][1000])
{
    word[0] = static_cast<char>(tolower(word[0]));
    for (int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            if(wordSearch[i][j] == word[0])
            {
                if (wordDirection(i, j, word, wordSearch, wordSearchAnswers))
                    return true;
            }
        }
    }
    return false;
}

// Finds the second letter of the word and decides what the direction is.
bool PuzzleSolver::wordDirection(int findWordRow, int findWordCol, std::string& word, char wordSearch[][1000],
                   char wordSearchAnswers[][1000])
{
    int incrementCol, incrementRow;
    for(int j = -1; j <= 1; j++)
    {
        for(int k = -1; k <= 1; k++)
        {
            incrementCol = k;
            incrementRow = j;
            if(wordSearch[findWordRow + j][findWordCol + k] == word[1])
            {
                if(checkForCompleteWord(findWordRow, findWordCol, word, incrementRow, incrementCol, wordSearch,
                                        wordSearchAnswers))
                    return true;
            }
        }
    }
    return false;
}

// Checks if the full word is found
bool PuzzleSolver::checkForCompleteWord(int findWordRow, int findWordCol, std::string& word, int incrementRow, int incrementCol,
                          char wordSearch[][1000], char wordSearchAnswers[][1000])
{
    int originalCol = findWordCol, originalRow = findWordRow;
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] == wordSearch[findWordRow][findWordCol])
        {
            findWordCol = findWordCol + incrementCol;
            findWordRow = findWordRow + incrementRow;
        }
        else
        {
            return false;
        }
    }
    for(int i=0; i < word.length(); i++)
    {
        wordSearchAnswers[originalRow][originalCol] = wordSearch[originalRow][originalCol];
        originalCol = originalCol + incrementCol;
        originalRow = originalRow + incrementRow;
    }
    return true;
}

// Outputs the word search board to the user by making all the letters lowercase
void PuzzleSolver::outputWordSearch(std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000])
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

// Outputs a message to the user
void PuzzleSolver::userOutput(std::string message)
{
    std::cout << message << std::endl;
}

// Gets input of type string from the user
void PuzzleSolver::userInputWord(std::string &word)
{
    std::cin >> word;
}

// Opens file of type ifstream
void PuzzleSolver::openFile(std::ifstream& in, std::string fileName)
{
    in.open(fileName);
    if (in.fail())
    {
        userOutput("Could not open file of type ifstream.");
        exit(2);
    }
}

// Closes file of type instream
void PuzzleSolver::closeFile(std::ifstream& in)
{
    in.close();
}