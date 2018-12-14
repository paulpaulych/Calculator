#include <iostream>
#include <fstream>

#include "Calculator.h"

int main(int argc, char ** argv) {
    Calculator calc;
    if(argc > 1) {
        std::ifstream in(argv[1]);
        try {
            calc.run(in);
        }
        catch(CriticalError& exc){
            std::cerr << exc.what() << std::endl;
        }
    }
    else{
        try {
            calc.run(std::cin);
        }
        catch(CriticalError& exc) {
            std::cerr << exc.what() << std::endl;
        }
    }
    return 0;
}