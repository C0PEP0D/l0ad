// Std includes
#include <iostream>
#include <vector>
#include <string>
// Lib includes
#include "l0ad/ascii/double.h"

int main () {
    double loaded = -1;
    l0ad::ascii::loadDouble(std::string("../data/save.txt"), loaded, '\n');
    std::cout << "value loaded: " << loaded << std::endl;
}
