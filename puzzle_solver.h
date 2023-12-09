//
// Created by Kathleen Nguyen on 12/9/23.
//

#ifndef WORD_SEARCH_PUZZLE_SOLVER_H
#define WORD_SEARCH_PUZZLE_SOLVER_H
#include <iostream>
#include <fstream>
#include <string>

// Solves an existing puzzle
class PuzzleSolver {
private:
    std::string fileName;
    void openFile(std::ifstream& in, std::string fileName);
    void closeFile(std::ifstream& in);

public:
    PuzzleSolver();
    void solvePuzzle(std::ifstream& in);
    bool findWord(std::string& word, int maxRows, int maxCols, char wordSearch[][1000], char wordSearchAnswers[][1000]);
    bool wordDirection(int findWordRow, int findWordCol, std::string& word, char wordSearch[][1000],
                       char wordSearchAnswers[][1000]);
    bool checkForCompleteWord(int findWordRow, int findWordCol, std::string& word, int incrementRow, int incrementCol,
                              char wordSearch[][1000], char wordSearchAnswers[][1000]);
    void outputWordSearch(std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000]);
    void userOutput(std::string message);
    void userInputWord(std::string &word);
};


#endif //WORD_SEARCH_PUZZLE_SOLVER_H
