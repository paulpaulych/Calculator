#include "Context.h"

Context::Context(){
    variables = new std::map<std::string, double>;
    stack = new std::stack<double>;
}

Context::~Context(){
    delete variables;
    delete stack;
    variables = nullptr;
    stack = nullptr;
}

double Context::stackPop(){
    if(stack->empty()){
        throw CriticalError("STACK_UNDERFLOW");
    }
    double ret = stack->top();
    stack->pop();
    return ret;
}

void Context::stackPush(double x){
    stack->push(x);
}

bool Context::stackEmpty(){
    return stack->empty();
}

double Context::stackTop(){
    return stack->top();
}

void Context::addVar(std::string name, double val){
    (*variables)[name] = val;
}

double Context::getVar(std::string name){
    double ret;
    try{
        ret = variables->at(name);
    }
    catch(std::out_of_range& exc){
        throw NonCriticalError("unknown variable \"" + name + "\"");
    }
    return ret;
}