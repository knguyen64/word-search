//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "puzzle_opener.h"

// Initializes a new instance of PuzzleOpener class
PuzzleOpener::PuzzleOpener() {

}

// Opens a file of the name inputted by the user. The file is read and outputted as all lowercase
void PuzzleOpener::openPuzzle(std::ifstream& in)
{
    char symbol;
    userOutput("What puzzle would you like to open?");
    userInputWord(fileName);

    openFile(in, fileName);

    in.get(symbol);
    while (!in.eof())
    {
        std:: cout << symbol;
        if(!in.eof())
        {
            in.get(symbol);
        }
    }
    closeFile(in);
}

// Outputs a message to the user
void PuzzleOpener::userOutput(std::string message)
{
    std::cout << message << std::endl;
}

// Gets input of type string from the user
void PuzzleOpener::userInputWord(std::string &word)
{
    std::cin >> word;
}

// Opens file of type ifstream
void PuzzleOpener::openFile(std::ifstream& in, std::string fileName)
{
    in.open(fileName);
    if (in.fail())
    {
        userOutput("Could not open file of type ifstream.");
        exit(2);
    }
}

// Closes file of type instream
void PuzzleOpener::closeFile(std::ifstream& in)
{
    in.close();
}