// EmptyStack.h
#pragma once
#include <stdexcept>
#include <string>

class EmptyStack : public std::runtime_error {
public:
    EmptyStack(const std::string& msg) : std::runtime_error(msg) {}
};
