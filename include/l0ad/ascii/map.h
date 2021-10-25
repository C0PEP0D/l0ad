#ifndef L0AD_MAP_H
#define L0AD_MAP_H
#pragma once

// include std
#include <string> // string
#include <memory> // shared_ptr
#include <map>
#include <sstream> //istringstream
// include modules
#include "l0ad/ascii/load.h"

namespace l0ad {

namespace ascii {

template<typename TypeConverterData, template<typename, typename...> class TypeMap, typename TypeArray, typename TypeData>
class ConverterCsvToMap : public Converter<TypeMap<std::string, TypeArray>> {
    public:
        ConverterCsvToMap(const std::shared_ptr<TypeConverterData>& p_sConverter) : sConverter(p_sConverter) {
        }
    public:
        void operator()(std::istream& file, TypeMap<std::string, TypeArray>& loaded, char delimiter) const override {
            std::string key;
            // Read header
            std::string line;
            std::getline(file, line);
            line.erase(line.begin());
            std::istringstream iHeaderStream;
            iHeaderStream.str(line);
            while(std::getline(iHeaderStream, key, delimiter)) {
                loaded[key] = TypeArray();
            }
            // Read data
            while(std::getline(file, line)) {
                std::istringstream iLineStream;
                iLineStream.str(line);
                for(auto &pair: loaded) {
                    pair.second.push_back(0.0);
                    (*sConverter)(iLineStream, pair.second.back(), delimiter);
                }
            }
        }
    public:
        std::shared_ptr<TypeConverterData> sConverter;
};


template<typename TypeConverterData, template<typename, typename...> class TypeMap, typename TypeArray, typename TypeData>
void loadCsvToMap(const std::string& fileName, TypeMap<std::string, TypeArray>& loaded, char delimiter) {
    load(fileName, ConverterCsvToMap<TypeConverterData, TypeMap, TypeArray, TypeData>(std::make_shared<TypeConverterData>()), loaded, delimiter);
}

}

}

#endif
