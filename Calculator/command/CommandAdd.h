#pragma once

#include "pch.h"

class CommandAdd : public Command{
public:
    void execute(std::vector<std::string>& args, Context * context) final;
};

