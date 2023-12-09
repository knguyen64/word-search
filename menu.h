//
// Created by Kathleen Nguyen on 12/9/23.
//

#ifndef WORD_SEARCH_MENU_H
#define WORD_SEARCH_MENU_H
#include <iostream>
#include <string>

// Outputs the menu to the user and prompts them to create a word search, open a word search, solve a word search,
// or exit the program
class Menu {
private:
    int option;

public:
    Menu();
    void run();
    void userOutput(std::string message);
    void setOption();
    int getOption();
};


#endif //WORD_SEARCH_MENU_H
