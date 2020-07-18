#include "menu.hh"

Menu::Menu(): datahandler_(DataHandler()) {
    std::cout << START_TXT << std::endl << std::endl;
}

bool Menu::event() {
    std::string action = askUserInput();

    // Namelist in alphabetical order
    if (action == "A" || action == "a") {
        intoAlphabetical();
    }

    // CSV-format
    else if (action == "C" || action == "c") {
        intoCSV();
    }

    // Close the program
    else if (action == "Q" || action == "q") {
        return false;
    }

    // Bad input
    else {
        std::cout << "Paska input, yrit\x84 edes." << std::endl << std::endl;
    }

    return true;
}

std::string Menu::askUserInput() {
    std::string input = "";
    std::cout << MENU_TXT << std::endl;
    std::cout << "Toiminto: ";
    std::cin >> input;
    return input;
}

void Menu::intoAlphabetical() {
    if (datahandler_.convertToAlphabetical()) {
        std::cout << "Datan muunnos onnistui." << std::endl << std::endl;
    }
    else {
        std::cout << "Datan muunnos ep\x84onnistui." << std::endl << std::endl;
    }
}

void Menu::intoCSV() {
    if (datahandler_.convertToCSV()) {
        std::cout << "Datan muunnos onnistui." << std::endl << std::endl;
    }
    else {
        std::cout << "Datan muunnos ep\x84onnistui." << std::endl << std::endl;
    }
}
