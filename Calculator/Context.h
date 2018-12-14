#pragma once

#include <string>
#include <stack>
#include <map>
#include "MyException.h"

class Context{
    std::map<std::string, double> * variables;
    std::stack<double> * stack;
public:
    Context();
    ~Context();

    double stackPop();
    void stackPush(double x);
    bool stackEmpty();
    double stackTop();

    void addVar(std::string name, double val);
    double getVar(std::string name);
};

