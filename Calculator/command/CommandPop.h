#pragma once

#include "pch.h"

class CommandPop : public Command{
public:
    void execute(std::vector<std::string>& args, Context * context) final;
};
