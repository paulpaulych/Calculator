#pragma once
#include <string>

class Parcer {
    std::string line;
    unsigned int sizeOfLine;
    unsigned int cur = 0, prev = 0;
public:
    Parcer(std::string&);
    bool readWord(std::string &word);
};