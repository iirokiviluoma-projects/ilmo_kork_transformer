#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


#ifndef DATAHANDLER_HH
#define DATAHANDLER_HH

const std::string DATA_FILE = "data.txt";

/**
 * @brief The Info struct can be used to store information.
 */
struct Info {
    std::string number;
    std::string first_name;
    std::string surname;
    std::string email;
    std::string extra_info;
};

/**
 * @brief The DataHandler class handles working with data.
 */
class DataHandler
{
public:
    /**
     * @brief DataHandler is constructor for the class.
     */
    DataHandler();

    /**
     * @brief convertToAlphabetical modifies data to an alphabetical name list.
     * @return true - if data modification was successful.
     *         false - otherwise.
     */
    bool convertToAlphabetical();

    /**
     * @brief convertToCSV modifies data to CSV-format.
     * @return true - if data modification was successful.
     *         false - otherwise.
     */
    bool convertToCSV();
private:
    /**
     * @brief readDataFromFile reads data from the input file and stores it in the vector.
     * @param data is a vector where all information will be stored.
     */
    void readDataFromFile(std::vector<Info>& data);

    /**
     * @brief writeDataToAlphabetical writes the data in the chosen file in alphabetical order.
     * @param data is a vector containing all data to be written.
     */
    void writeDataToAlphabetical(const std::vector<Info>& data);

    /**
     * @brief writeDataToCSV writes the data in the chosen file in CSV-format.
     * @param data
     */
    void writeDataToCSV(const std::vector<Info>& data);

    /**
     * @brief convertToInfo converts a vector containing information to Info-struct.
     * @param splitted_line is a vector containing elements for a single Info-struct.
     * @return
     */
    Info convertToInfo(std::vector<std::string>& splitted_line);

    /**
     * @brief convertToAlphabeticalString gives the data in writeable form for
     * alphabetical name list.
     * @param i is Info-struct.
     * @param num is a running number of the Info.
     * @return string in writeable form.
     */
    std::string convertToAlphabeticalString(Info i, unsigned int num);

    /**
     * @brief convertToCSVStringgives the data in writeable form for CSV-format.
     * @param i is Info-struct.
     * @return string in writeable form.
     */
    std::string convertToCSVString(Info i);

    /**
     * @brief split splits a given line from chosen points.
     * @param line is the line to be splitted.
     * @param delimiter is a char where a line will be splitted.
     * @return vector containing the splitted elements.
     */
    std::vector<std::string> split(const std::string& line, const char delimiter = '\t');
};

#endif // DATAHANDLER_HH
