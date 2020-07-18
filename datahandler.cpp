#include "datahandler.hh"

bool compareBySurname(const Info& i_1, const Info& i_2) {
    return i_1.surname < i_2.surname;
}

DataHandler::DataHandler() {
    // Tests if data.txt already exists.
    std::ifstream file(DATA_FILE);

    if (!file) {
        std::ofstream new_data_file(DATA_FILE);
        new_data_file.close();
    }
    else {
        file.close();
    }
}

bool DataHandler::convertToAlphabetical() {
    std::vector<Info> data = {};
    readDataFromFile(data);

    if (data.empty()) {
        std::cout << "Dataa ei l\x94ytynyt." << std::endl;
        return false;
    }

    writeDataToAlphabetical(data);
    return true;
}

bool DataHandler::convertToCSV() {
    std::vector<Info> data = {};
    readDataFromFile(data);

    if (data.empty()) {
        std::cout << "Dataa ei l\x94ytynyt." << std::endl;
        return false;
    }

    writeDataToCSV(data);
    return true;
}

void DataHandler::readDataFromFile(std::vector<Info>& data) {
    std::ifstream file(DATA_FILE);

    std::string line = "";

    while (std::getline(file, line)) {
        std::vector<std::string> splitted = split(line);

        data.push_back(convertToInfo(splitted));
    }
}

void DataHandler::writeDataToAlphabetical(const std::vector<Info>& data) {
    std::vector<Info> data_sorted = data;
    std::sort(data_sorted.begin(), data_sorted.end(), compareBySurname);

    std::string output_file_name = "";
    std::cout << "Tiedoston nimi, johon tiedot tallennetaan "
                 "(ilman tiedostop\x84\x84tett\x84): ";
    std::cin >> output_file_name;
    output_file_name = output_file_name + ".txt";
     std::ofstream output_file(output_file_name);

     unsigned int num = 1;

    for (auto i : data_sorted) {
        output_file << convertToAlphabeticalString(i, num) << std::endl;
        ++num;
    }

    output_file.close();
    std::cout << "Tiedot kirjoitettu tiedostoon: " + output_file_name << std::endl;
}

void DataHandler::writeDataToCSV(const std::vector<Info>& data) {
    std::string output_file_name = "";
    std::cout << "Tiedoston nimi, johon tiedot tallennetaan "
                 "(ilman tiedostop\x84\x84tett\x84): ";
    std::cin >> output_file_name;
    output_file_name = output_file_name + ".csv";
    std::ofstream output_file(output_file_name);
    const char* BOM = "\xef\xbb\xbf";
    output_file << BOM;

    for (auto i : data) {
        output_file << convertToCSVString(i) << std::endl;
    }

    output_file.close();
    std::cout << "Tiedot kirjoitettu tiedostoon: " + output_file_name << std::endl;
}

Info DataHandler::convertToInfo(std::vector<std::string>& splitted_line) {
    std::string number = splitted_line.at(0);

    std::string name = splitted_line.at(1);
    std::string first_name;
    std::string surname;

    if (name.size() == 1) {
        first_name = name;
        surname = "";
    }
    else {
        std::vector<std::string> name_splitted = split(name, ' ');
        first_name = name_splitted.at(0);
        surname = name_splitted.at(1);
        std::transform(surname.begin(), surname.end(), surname.begin(), ::tolower);
        surname[0] = std::toupper(surname[0]);
    }

    std::string& email = splitted_line.at(2);

    std::string extra_info = splitted_line.at(3);

    return Info({number, first_name, surname, email, extra_info});
}

std::string DataHandler::convertToAlphabeticalString(Info i, unsigned int num) {
    return std::to_string(num) + "\t" + i.surname + "\t" + i.first_name;
}

std::string DataHandler::convertToCSVString(Info i) {
    return i.number + ';' + i.first_name + ';' + i.surname + ';' + i.email + ';' + i.extra_info;
}

std::vector<std::string> DataHandler::split(const std::string& line, const char delimiter) {
    std::vector<std::string> splitted_line = {};
    std::string temp = line;

    while (temp.find(delimiter) != std::string::npos) {
        unsigned int index = static_cast<unsigned int>(temp.find(delimiter));
        std::string part = temp.substr(0, index);
        temp = temp.substr(index+1, temp.size());

        splitted_line.push_back(part);
    }

    if (!temp.empty()) {
        splitted_line.push_back(temp);
    }

    return splitted_line;
}
