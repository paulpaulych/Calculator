#include "CommandPop.h"

static CommandCreator<CommandPop> maker("POP");

void CommandPop::execute(std::vector<std::string>& args, Context * context){
    try{
        context->stackPop();
    }
    catch(CriticalError& exc){
        throw exc;
    }
}