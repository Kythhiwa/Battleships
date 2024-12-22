//
// Created by Kythhiwa on 30.11.2024.
//

#ifndef OOP_FILERAII_H
#define OOP_FILERAII_H
#include <fstream>
#include <string>
#include <iostream>
class FileRAII {
public:
    FileRAII(const std::string& filename, std::ios_base::openmode mode);
    ~FileRAII();
    std::fstream& getStream();
    bool isOpen() const;
private:
    std::fstream file;
};

#endif //OOP_FILERAII_H
