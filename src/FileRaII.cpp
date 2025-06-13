//
// Created by Kythhiwa on 30.11.2024.
//

#include "FileRaII.h"
FileRAII::FileRAII(const std::string &filename, std::ios_base::openmode mode) : file(filename, mode){
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
    } else {
        std::cout << "File opened successfully: " << filename << std::endl;
    }
}

FileRAII::~FileRAII() {
    if (file.is_open()) {
        file.close();
        std::cout << "File closed." << std::endl;
    }
}

std::fstream& FileRAII::getStream() {
    return file;
}

bool FileRAII::isOpen() const {
    return file.is_open();
}