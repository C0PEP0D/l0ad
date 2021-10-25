#ifndef L0AD_LOAD_H
#define L0AD_LOAD_H
#pragma once

// include std
#include <fstream> // ifstream
#include <string> // string
// include modules

namespace l0ad {

namespace ascii {

template<typename TypeConverted>
class Converter {
    public:
        virtual void operator()(std::istream& file, TypeConverted& loaded, char delimiter) const = 0;
};

template<typename TypeLoaded, typename TypeConverter>
void load(const std::string& fileName, const TypeConverter& converter, TypeLoaded& loaded, char delimiter) {
    // open file
    std::ifstream file(fileName);
    // load
    converter(file, loaded, delimiter);
    // close file
    file.close();
}

}

}

#endif
