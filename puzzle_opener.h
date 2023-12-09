//
// Created by Kathleen Nguyen on 12/9/23.
//

#ifndef WORD_SEARCH_PUZZLE_OPENER_H
#define WORD_SEARCH_PUZZLE_OPENER_H
#include <iostream>
#include <fstream>
#include <string>


class PuzzleOpener {
private:
    std::string fileName;
    void openFile(std::ifstream& in, std::string fileName);
    void closeFile(std::ifstream& in);
public:
    PuzzleOpener();
    void openPuzzle();
    void userOutput(std::string message);
    void userInputWord(std::string &word);

};


#endif //WORD_SEARCH_PUZZLE_OPENER_H
