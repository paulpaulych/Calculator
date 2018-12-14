#include "CommandPush.h"

static CommandCreator<CommandPush> maker("PUSH");

void CommandPush::execute(std::vector<std::string>& args, Context * context){
    if(args.empty()){
        throw NonCriticalError("PUSH: an argument requred");
    }
    double val;
    try{
        val = stod(args[0]);
    }
    catch (std::invalid_argument &exc) {
        try{
            val = context->getVar(args[0]);
        }
        catch(NonCriticalError& exc){
            throw NonCriticalError("PUSH: undefined variable");
        }
    }
    context->stackPush(val);
}