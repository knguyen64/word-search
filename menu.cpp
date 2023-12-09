//
// Created by Kathleen Nguyen on 12/9/23.
//

#include "menu.h"

Menu::Menu() {

}

// Outputs word search menu
void Menu::run() {
    userOutput("Choose an option:");
    userOutput("(1) Create a new puzzle");
    userOutput("(2) Open an existing puzzle");
    userOutput("(3) Solve an existing puzzle");
    userOutput("(4) Exit\n");
    userOutput("Choice: ");
    setOption();
}

// Outputs text
void Menu::userOutput(std::string message)
{
    std::cout << message << std::endl;
}

// Gets user input for option
void Menu::setOption() {
    std::cin >> option;
}

// Returns option
int Menu::getOption() {
    return option;
}
