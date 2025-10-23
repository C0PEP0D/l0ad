#ifndef L0AD_BIN_LOAD_H
#define L0AD_BIN_LOAD_H
#pragma once

// include std
#include <fstream> // ifstream
#include <string> // string
#include <sstream> // istringstream
#include <filesystem> // file_size
// include modules

namespace l0ad {

namespace bin {

template<typename TypeLoaded>
void load(const std::string& fileName, TypeLoaded* pLoaded, const std::size_t n) {
	// open file
	std::ifstream file(fileName, std::ios::binary);
	// load
	file.read(reinterpret_cast<char*>(pLoaded), n * sizeof(TypeLoaded));
	// close file
	file.close();
}

template<typename TypeLoaded, template<typename> typename TypeVector>
void loadVector(const std::string& fileName, TypeVector<TypeLoaded>& loaded) {
	// open file
	unsigned int file_size = std::filesystem::file_size(fileName);
	std::ifstream file(fileName);
	// load
	loaded.resize(file_size / sizeof(TypeLoaded));
	file.read(reinterpret_cast<char*>(loaded.data()), loaded.size() * sizeof(TypeLoaded));
	// close file
	file.close();
}

}

}

#endif
