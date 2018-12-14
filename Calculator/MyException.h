#pragma once

#include <stdexcept>
#include <string>

class CriticalError : public std::runtime_error {
public:
    explicit CriticalError(const std::string& what_arg) : runtime_error(what_arg){}
    explicit CriticalError(const char* what_arg) : runtime_error(what_arg){}
};

class NonCriticalError : public std::runtime_error{
public:
    explicit NonCriticalError(const std::string& what_arg) : runtime_error(what_arg){}
    explicit NonCriticalError(const char* what_arg) : runtime_error(what_arg){}
};