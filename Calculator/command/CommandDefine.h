#pragma once

#include "pch.h"

class CommandDefine : public Command{
public:
    void execute(std::vector<std::string>& args, Context * context) final {
        if(args.size() < 2){
            throw NonCriticalError("DEFINE: too few arguments");
        }
        try {
            context->addVar(args[0], stod(args[1]));
        }
        catch (std::invalid_argument &exc) {
            throw  NonCriticalError("DEFINE: second argument must be double");
        }
    }
};
