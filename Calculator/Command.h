#pragma once

#include <vector>
#include <string>
#include <map>
#include <limits>
#include <iostream>
#include <cmath>
#include "Context.h"

class Command {
public:
    virtual void execute(std::vector<std::string>&, Context * context){}
};