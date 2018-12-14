#include "CommandMul.h"

static CommandCreator<CommandMul> maker("*");

void CommandMul::execute(std::vector<std::string>& args, Context * context){
    double tmp;
    try {
        tmp = context->stackPop() * context->stackPop();
    }
    catch(CriticalError& exc) {
        throw exc;
    }
    if(FP_INFINITE == std::fpclassify(tmp)){
        throw std::range_error("MUL: result of MUL is out of range");
    }
    if(tmp != tmp){
        throw std::range_error("MUL: NaN result returned");
    }
    context->stackPush(tmp);
}