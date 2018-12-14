#pragma once
#include "Command.h"

class ICommandCreator {
public:
    virtual Command * Create() = 0;
    virtual ~ICommandCreator() {}
};