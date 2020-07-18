#include "datahandler.hh"
#include <iostream>

#ifndef MENU_HH
#define MENU_HH

const std::string VERSION = "v1.0";

const std::string START_TXT = "IlmoKork_DataHandler " + VERSION + " by Iiro\n"
                              "Muuntaa ilmo.kork.fi:sta kopioidut tiedot "
                              "CSV-muotoon tai aakkostettuun nimilistaan.\n\n"
                              "Kopioi tiedot osallistujatiedot ensimm\x84isest\x84 "
                              "numerosta (1) l\x84htien viimeisen\nLis\x84tiedot-"
                              "kent\x84n loppuun ja liit\x84 ne data.txt-tiedostoon.\n"
                              "data.txt l\x94ytyy samasta kansiosta kuin t\x84m\x84 ohjelma.\n"
                              "data.txt t\x84ytyy olla suljettuna toimintoja suoritettaessa.\n\n"
                              "Tarkemmat ohjeet l\x94ytyv\x84t README-tiedostosta.";

const std::string MENU_TXT = "Valitse toiminto:\n"
                             "A/a = Aakkostettu nimilista\n"
                             "C/c = CSV-muoto\n"
                             "Q/q = Sulje ohjelma\n";

/**
 * @brief The Menu class serves as the menu for the program. Asks input from user
 * and tells the data handler class how to modify it.
 */
class Menu
{
public:
    /**
     * @brief Menu is constructor for the class.
     */
    Menu();

    /**
     * @brief event handles passing user input to
     * @return false - if user chose to shut down the program.
     *         true - otherwise.
     */
    bool event();

private:
    /**
     * @brief askUserInput asks user from input and returns it.
     * @return string, containing input from user.
     */
    std::string askUserInput();

    /**
     * @brief intoAlphabetical handles the case when user chose the alphabetical order option.
     */
    void intoAlphabetical();

    /**
     * @brief intoCSV handles the case when user chose the CSV-format option.
     */
    void intoCSV();

    DataHandler datahandler_;

};

#endif // MENU_HH
