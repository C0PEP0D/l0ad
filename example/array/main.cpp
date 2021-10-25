// Std includes
#include <iostream>
#include <vector>
#include <string>
// Lib includes
#include "l0ad/ascii/double.h"

int main () {
    std::vector<double> loaded(10);
    l0ad::ascii::loadArrayDouble(std::string("../data/save.csv"), loaded, ',');
    // output
    std::cout << "loaded values"<< std::endl;
    for (auto& l : loaded) {
        std::cout << l << " ";
    }
    std::cout << std::endl;
}
