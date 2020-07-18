#include "menu.hh"
#include <iostream>
#include <vector>

// IlmoKoRK_DataHandler modifies data taken from ilmo.kork.fi to a form that
// is easy to work with.

void eventLoop() {
    Menu m = Menu();

    std::string action = "";

    while (true) {
        if (!m.event()) return;
    }

}

int main() {
    eventLoop();
    return EXIT_SUCCESS;
}
