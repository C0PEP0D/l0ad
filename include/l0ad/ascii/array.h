#ifndef L0AD_ARRAY_H
#define L0AD_ARRAY_H
#pragma once

// include std
#include <string> // string, stod
#include <memory> // shared_ptr
// include modules
#include "l0ad/ascii/load.h"

namespace l0ad {

namespace ascii {

template<typename TypeConverterData, typename TypeArray, typename TypeData>
class ConverterArray : public Converter<TypeArray> {
    public:
        ConverterArray(const std::shared_ptr<TypeConverterData>& p_sConverter) : sConverter(p_sConverter) {
        }
    public:
        void operator()(std::istream& file, TypeArray& loaded, char delimiter) const override {
            for(auto& sub : loaded) {
                (*sConverter)(file, sub, delimiter);
            }
        }
    public:
        std::shared_ptr<TypeConverterData> sConverter;
        std::string delimiter;
};


template<typename TypeConverterData, typename TypeArray, typename TypeData>
void loadArray(const std::string& fileName, TypeArray& loaded, char delimiter) {
    return load<TypeArray, ConverterArray<TypeConverterData, TypeArray, TypeData>>(fileName, ConverterArray<TypeConverterData, TypeArray, TypeData>(std::make_shared<TypeConverterData>()), loaded, delimiter);
}

}

}

#endif
