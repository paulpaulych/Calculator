#include "Parcer.h"
#include <string>

Parcer::Parcer(std::string &inputLine) {
    line = inputLine;
    sizeOfLine = line.size();
}

bool Parcer::readWord(std::string &word){
    while(line[cur] == ' ' && cur != sizeOfLine) cur++;
    if(cur == sizeOfLine) {
        return false;
    }
    prev = cur;
    while(line[cur] != ' ' && cur != sizeOfLine) cur++;
    word = line.substr(prev, cur - prev);
    return true;
};
