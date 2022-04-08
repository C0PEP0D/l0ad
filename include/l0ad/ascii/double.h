#ifndef L0AD_ASCII_DOUBLE_H
#define L0AD_ASCII_DOUBLE_H
#include <fstream>
#pragma once

// include std
#include <fstream> // ifstream, getline
#include <string> // string, stod
// include modules
#include "l0ad/ascii/load.h"

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


void loadDouble(const std::string& fileName, double* pLoaded, const size_t n, const char delimiter = '\n') {
    load<double, ConverterDouble>(fileName, pLoaded, n, delimiter, ConverterDouble());
}

template<typename TypeVector>
void loadVectorDouble(const std::string& fileName, TypeVector& loaded, char delimiter = '\n') {
    loadVector<TypeVector, ConverterDouble>(fileName, loaded, delimiter, ConverterDouble());
}

template<template<typename, typename...> class TypeMap, typename TypeVector>
void loadCsvToMapDouble(const std::string& fileName, TypeMap<std::string, TypeVector>& loaded, const char delimiter = ',') {
    loadCsvToMap<TypeMap, TypeVector, ConverterDouble>(fileName, loaded, delimiter);
}

}

}

#endif
