// Std includes
#include <iostream>
#include <vector>
#include <string>
// Lib includes
#include "l0ad/bin/load.h"

int main () {
    std::vector<double> loaded;
    l0ad::bin::loadVector(std::string("../data/save.bin"), loaded);
    // output
    std::cout << "loaded values"<< std::endl;
    for (auto& l : loaded) {
        std::cout << l << " ";
    }
    std::cout << std::endl;
}
