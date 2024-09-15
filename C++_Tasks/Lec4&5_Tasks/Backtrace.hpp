//---------  lec 4,5 ----------
// author: Ebrahim Mostafa
// Backtrace.hpp file
#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <vector>
#include <string>

class Backtrace {
public:
    void enter(const std::string& functionName);
    void exit();
    void printBacktrace() const;

private:
    std::vector<std::string> callStack;
};

#endif // BACKTRACE_HPP
