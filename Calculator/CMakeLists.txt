cmake_minimum_required(VERSION 3.12)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator
        Calculator.cpp
        Calculator.h
        Parcer.cpp
        Parcer.h
        CommandFactory.h
        Command.h
        Context.h
        MyException.h
        command/CommandAdd.h
        command/CommandPush.h
        command/CommandPop.h
        command/CommandPrint.h
        command/CommandDefine.h
        command/CommandMul.h
        command/CommandDiv.h
        command/CommandSub.h
        command/CommandSqrt.h
        main.cpp
        command/pch.h CommandFactory.cpp CommandCreator.h command/CommandAdd.cpp command/CommandDefine.cpp command/CommandDiv.cpp command/CommandMul.cpp command/CommandPop.cpp command/CommandPrint.cpp command/CommandPush.cpp command/CommandSqrt.cpp command/CommandSub.cpp ICommandCreator.h Context.cpp command/CommandNeg.cpp command/CommandNeg.h)