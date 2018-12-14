#pragma once

#include <map>
#include <string>
#include <stack>
#include "Context.h"

class Calculator {
    Context * context;
public:
    Calculator(){
        context = new Context;
    }
    bool run(std::istream& in);
    ~Calculator(){
        delete context;
    }
};

