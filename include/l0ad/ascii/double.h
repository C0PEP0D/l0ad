#ifndef L0AD_DOUBLE_H
#define L0AD_DOUBLE_H
#include <fstream>
#pragma once

// include std
#include <fstream> // ifstream, getline
#include <string> // string, stod
// include modules
#include "l0ad/ascii/array.h"
#include "l0ad/ascii/map.h"

namespace l0ad {

namespace ascii {

class ConverterDouble : public Converter<double> {
    public:
        void operator()(std::istream& file, double& loaded, char delimiter) const override {
            std::string str;
            std::getline(file, str, delimiter);
            loaded = std::stod(str);
        }
};


void loadDouble(const std::string& fileName, double& loaded, char delimiter) {
    load<double, ConverterDouble>(fileName, ConverterDouble(), loaded, delimiter);
}

template<typename TypeArray>
void loadArrayDouble(const std::string& fileName, TypeArray& loaded, char delimiter) {
    loadArray<ConverterDouble, TypeArray, double>(fileName, loaded, delimiter);
}

template<template<typename, typename...> class TypeMap, typename TypeArray>
void loadCsvToMapDouble(const std::string& fileName, TypeMap<std::string, TypeArray>& loaded, char delimiter) {
    loadCsvToMap<ConverterDouble, TypeMap, TypeArray, double>(fileName, loaded, delimiter);
}

}

}

#endif
