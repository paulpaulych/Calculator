#include "CommandSub.h"

static CommandCreator<CommandSub> maker("-");

void CommandSub::execute(std::vector<std::string>& args, Context * context){
    double tmp;
    try {
        tmp = context->stackPop() - context->stackPop();
    }
    catch(CriticalError& exc) {
        throw exc;
    }
    if(FP_INFINITE == std::fpclassify(tmp)){
        throw std::range_error("SUB: result of SUB is out of range");
    }
    if(tmp != tmp){
        throw std::range_error("SUB: NaN result returned");
    }
    context->stackPush(tmp);
}