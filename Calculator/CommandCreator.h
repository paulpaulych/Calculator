#pragma once

#include "CommandFactory.h"
#include "ICommandCreator.h"

template<typename T>
class CommandCreator : public ICommandCreator{
public:
    CommandCreator(const std::string& key){
        CommandFactory::instance().registerCreator(key, this);
    }
    virtual Command * Create(){
        return new T();
    }
};