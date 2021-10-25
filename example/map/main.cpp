// Std includes
#include <iostream>
#include <vector>
#include <string>
// Lib includes
#include "l0ad/ascii/double.h"

int main () {
    std::map<std::string, std::vector<double>> loaded;
    l0ad::ascii::loadCsvToMapDouble(std::string("../data/save.csv"), loaded, ',');
    // output
    std::cout << "loaded values"<< std::endl;
    for (auto& pair : loaded) {
        std::cout << pair.first << ": ";
        for (auto& value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
