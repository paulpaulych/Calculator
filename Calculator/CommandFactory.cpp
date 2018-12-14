#include "CommandFactory.h"
#include "CommandCreator.h"
#include "stdexcept"
#include "MyException.h"

CommandFactory& CommandFactory::instance() {
    static CommandFactory factory;
    return factory;
}

void CommandFactory::registerCreator(const std::string &key, ICommandCreator * newCreator) {
    if(creators.find(key) != creators.end()){
        throw CriticalError("Multiple creators for given key");
    }
    creators[key] = newCreator;
}

Command* CommandFactory::create(const std::string& key) {
    auto it = creators.find(key);
    if(it == creators.end()){
        throw NonCriticalError("Unknown command \"" + key + "\"");
    }
    ICommandCreator * creator = it->second;
    return creator->Create();
}