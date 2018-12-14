#include "CommandNeg.h"

static CommandCreator<CommandNeg> maker("=");

void CommandNeg::execute(std::vector<std::string> &args, Context *context) {
    try {
        context->stackPush(-context->stackPop());
    }
    catch(CriticalError& exc){
        throw exc;
    }
    catch(NonCriticalError& exc){
        throw exc;
    }
}