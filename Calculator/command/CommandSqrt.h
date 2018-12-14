#pragma once

#include "pch.h"

class CommandSqrt : public Command{
public:
    void execute(std::vector<std::string>& args, Context * context) final;
};
