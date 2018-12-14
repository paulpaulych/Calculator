#include "CommandDiv.h"

static CommandCreator<CommandDiv> maker("/");

void CommandDiv::execute(std::vector<std::string>& args, Context * context) {
    double left, right;
    try {
        left = context->stackPop();
    }
    catch (CriticalError &exc) {
        throw exc;
    }
    try {
        right = context->stackPop();
    }
    catch (CriticalError &exc) {
        throw exc;
    }
    if (right == 0.0) {
        throw NonCriticalError("can't divide by zero");
    }
    left /= right;
    if (FP_INFINITE == std::fpclassify(left)) {
        throw std::range_error("DIV: result of DIV is out of range");
    }
    if (left != left) {
        throw std::range_error("DIV: NaN result returned");
    }
    context->stackPush(left);
}