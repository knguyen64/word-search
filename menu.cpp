//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "menu.h"

// Initializes a new instance of Menu class
Menu::Menu() {

}

// Outputs the menu of prompts to the user
void Menu::run() {
    userOutput("Choose an option:");
    userOutput("(1) Create a new puzzle");
    userOutput("(2) Open an existing puzzle");
    userOutput("(3) Solve an existing puzzle");
    userOutput("(4) Exit\n");
    userOutput("Choice: ");
    setOption();
}

// Outputs a message to the user
void Menu::userOutput(std::string message)
{
    std::cout << message << std::endl;
}

// Gets user input of type int for option
void Menu::setOption() {
    std::cin >> option;
}

// Returns option
int Menu::getOption() {
    return option;
}
