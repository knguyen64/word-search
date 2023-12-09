//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "word_search.h"

WordSearch::WordSearch()
{

}

// Runs the word search
void WordSearch::run(){
    Menu menu;
    PuzzleGenerator generator;
    PuzzleOpener opener;
    int choice;
    bool menuAgain;

    do
    {
        menu.run();
        choice = menu.getOption();

        switch (choice)
        {
            case 1:
                generator.createWordSearch();
                menuAgain = true;
                break;
            case 2:
                opener.openPuzzle();
                menuAgain = true;
                break;
            case 4:
                exit(1);
        }
    } while (menuAgain);
}