//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "word_search.h"
std::ofstream fout;
std::ifstream fin;

// Initializes a new instance of WordSearch class
WordSearch::WordSearch()
{

}

// Runs the word search program
void WordSearch::run(){
    Menu menu;
    PuzzleGenerator generator;
    PuzzleOpener opener;
    PuzzleSolver solver;
    int choice;
    bool menuAgain = false;

    do
    {
        menu.run();
        choice = menu.getOption();

        switch (choice)
        {
            case 1:
                generator.createWordSearch(fout, fin);
                menuAgain = true;
                break;
            case 2:
                opener.openPuzzle(fin);
                menuAgain = true;
                break;
            case 3:
                solver.solvePuzzle(fin);
                menuAgain = true;
                break;
            case 4:
                exit(1);
        }
    } while (menuAgain);
}