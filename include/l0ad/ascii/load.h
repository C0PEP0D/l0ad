#ifndef L0AD_ASCII_LOAD_H
#define L0AD_ASCII_LOAD_H
#pragma once

// include std
#include <fstream> // ifstream
#include <string> // string
#include <sstream> // istringstream
// include modules

namespace l0ad {

namespace ascii {

template<typename TypeConverted>
class Converter {
	public:
		virtual void operator()(std::istream& file, TypeConverted& loaded, char delimiter) const = 0;
};

template<typename TypeLoaded, typename TypeConverter>
void load(const std::string& fileName, TypeLoaded* pLoaded, const std::size_t n, const char delimiter, const TypeConverter& converter) {
	// open file
	std::ifstream file(fileName);
	// load
	for (unsigned int i = 0; i < n; i++) {
		converter(file, pLoaded[i], delimiter);
	}
	// close file
	file.close();
}

template<typename TypeVector, typename TypeConverter>
void loadVector(const std::string& fileName, TypeVector& loaded, const char delimiter, const TypeConverter& converter) {
	// open file
	std::ifstream file(fileName);
	// load
	std::size_t index = 0;
	while(not file.eof()) {
		if(index >= loaded.size()) {
			loaded.emplace_back();
		}
		converter(file, loaded[index], delimiter);
		index++;
	}
	loaded.resize(index); // ensure loaded to be of the right size
	// close file
	file.close();
}

template<template<typename, typename...> class TypeMap, typename TypeVector, typename TypeConverter>
void loadCsvToMap(const std::string& fileName, TypeMap<std::string, TypeVector>& loaded, const char delimiter, const TypeConverter& converter) {
	// open file
	std::ifstream file(fileName);
	// read header
	std::string key;
	std::string line;
	std::getline(file, line);
	line.erase(line.begin());
	std::istringstream iHeaderStream(line);
	while(std::getline(iHeaderStream, key, delimiter)) {
		loaded[key] = TypeVector();
	}
	// Read data
    while(std::getline(file, line)) {
        std::istringstream iLineStream(line);
        for(auto &pair: loaded) {
            pair.second.emplace_back();
            converter(iLineStream, pair.second.back(), delimiter);
        }
    }
	// close file
	file.close();
}

}

}

#endif
