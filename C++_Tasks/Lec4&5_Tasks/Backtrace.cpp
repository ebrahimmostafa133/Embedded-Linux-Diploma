//---------  lec 4,5 ----------
// author: Ebrahim Mostafa
// Backtrace.cpp file
#include "Backtrace.hpp"
#include <iostream>

void Backtrace::enter(const std::string& functionName) {
    callStack.push_back(functionName);
    std::cout << "Enter to [" << functionName << "]" << std::endl;
}

void Backtrace::exit() {
    if (!callStack.empty()) {
        std::cout << "Exit from [" << callStack.back() << "]" << std::endl;
        callStack.pop_back();
    }
}

void Backtrace::printBacktrace() const {
    std::cout << "Backtrace as follows:" << std::endl;
    for (size_t i = 0; i < callStack.size(); ++i) {
        std::cout << i << "- " << callStack[callStack.size() - 1 - i] << std::endl;
    }
}
