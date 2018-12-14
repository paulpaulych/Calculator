#include "CommandPrint.h"

static CommandCreator<CommandPrint> maker("PRINT");

void CommandPrint::execute(std::vector<std::string>& args, Context * context){
    if(context->stackEmpty()){
        throw CriticalError("STACK_UNDERFLOW");
    }
    std::cout << context->stackTop() << std::endl;
}