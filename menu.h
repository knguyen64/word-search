//
// Created by Kathleen Nguyen on 12/9/23.
//

#ifndef WORD_SEARCH_MENU_H
#define WORD_SEARCH_MENU_H
#include <iostream>
#include <string>

// Ouputs the menu
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
