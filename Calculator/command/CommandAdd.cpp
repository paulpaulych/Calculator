#include "CommandAdd.h"

static CommandCreator<CommandAdd> maker("+");

void CommandAdd::execute(std::vector<std::string>& args, Context * context){
    double tmp;
    try {
        tmp = context->stackPop() + context->stackPop();
    }
    catch(CriticalError& exc) {
        throw exc;
    }
    if(FP_INFINITE == std::fpclassify(tmp)){
        throw std::range_error("ADD: result of adding is out of range");
    }
    if(tmp != tmp){
        throw std::range_error("ADD: NaN result returned");
    }
    context->stackPush(tmp);
}