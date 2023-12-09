//
// Created by Kathleen Nguyen on 12/9/23.
//

#ifndef WORD_SEARCH_PUZZLE_GENERATOR_H
#define WORD_SEARCH_PUZZLE_GENERATOR_H
#include <iostream>
#include <fstream>
#include <string>

// Creates and saves a word search puzzle using input from the user
class PuzzleGenerator {
private:
    int wordCount;

    void openFile(std::ofstream& out, std::string fileName);
    void closeFile(std::ofstream& out);
    void openFile(std::ifstream& in, std::string fileName);
    void closeFile(std::ifstream& in);

public:
    PuzzleGenerator();
    void createWordSearch();
    void createEmptyPuzzle(int& wordCount, int &maxRows, int &maxCols, char wordSearchLetters[][1000]);
    void fillWordSearch(std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000],
                        std::string& word);
    void randomSpot(int maxRows, int maxCols, int &randRow, int &randCol, char wordSearchLetters[][1000]);
    bool possibleDirectionCheck(int maxRows, int maxCols, int randRow, int randCol, int incrementRow, int incrementCol,
                                char wordSearchLetters[][1000], int wordLength, std::string& word);
    void writeWord(int randRow, int randCol, int incrementRow, int incrementCol, char wordSearchLetters[][1000],
                   int& wordLength, std::string& word);
    void outputWordSearch(std::ifstream& in, int maxRows, int maxCols, char wordSearchLetters[][1000]);
    void outputKey(std::ifstream& in);
    void saveWordSearch(std::ofstream& out, std::ifstream& in, int maxRows, int maxCols,
                        char wordSearchLetters[][1000]);
    void wordKey(std::ofstream& out, std::string& fileName, std::string& word);
    void userOutput(std::string message);
    void userInputNum(int &input);
    void userInputWord(std::string &word);


};


#endif //WORD_SEARCH_PUZZLE_GENERATOR_H
