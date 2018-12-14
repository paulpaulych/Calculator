#include "CommandSqrt.h"

static CommandCreator<CommandSqrt> maker("SQRT");

void CommandSqrt::execute(std::vector<std::string>& args, Context * context){
    double tmp;
    try {
        tmp = sqrt(context->stackPop());
    }
    catch(CriticalError& exc) {
        throw exc;
    }
    if(FP_INFINITE == std::fpclassify(tmp)){
        throw std::range_error("SQRT: result of SQRT is out of range");
    }
    if(tmp != tmp){
        throw std::range_error("SQRT: NaN result returned");
    }
    context->stackPush(tmp);
}