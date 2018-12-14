#include "Calculator.h"
#include "Parcer.h"
#include "CommandFactory.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "MyException.h"
#include "Command.h"
bool Calculator::run(std::istream & in){
    std::string line;
    while(std::getline(in, line)){
        Parcer curLine(line);
        if(line[0] == '#'){
            continue;
        }
        std::string commandName;
        if(curLine.readWord(commandName)){
            if(commandName == "EXIT")
                break;
            std::vector<std::string> args;
            std::string word;
            while(curLine.readWord(word)) {
                args.push_back(word);
            }
            try{
                Command * cur = CommandFactory::CommandFactory::instance().create(commandName);
                cur->execute(args, context);
            }
            catch(std::range_error& exc){
                std::cerr << exc.what() << std::endl;
            }
            catch(CriticalError& exc){
                throw exc;
            }
            catch(NonCriticalError& exc){
                std::cerr << exc.what() << std::endl;
            }
        }
    }
}