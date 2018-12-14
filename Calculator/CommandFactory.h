#pragma once

#include <map>
#include <string>

class Command;
class ICommandCreator;

class CommandFactory {
    std::map<std::string, ICommandCreator *> creators;
public:
    static CommandFactory& instance();
    void registerCreator(const std::string& key, ICommandCreator * newCreator);
    Command * create(const std::string&);
};
