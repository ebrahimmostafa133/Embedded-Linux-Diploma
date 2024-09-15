//---------  lec 4,5 ----------
// author: Ebrahim Mostafa
// Backtrace.cpp -->main file
// Create A class that can be used to make backtrace for calling functions

#include <iostream>
#include "Backtrace.hpp"

#define ENTER_FN() backtrace.enter(__FUNCTION__)
#define EXIT_FN() backtrace.exit()

Backtrace backtrace;

void fun1(int x);
void fun2(int x);
void fun3(int x);

void fun1(int x) {
    ENTER_FN();
    fun2(x);
    EXIT_FN();
}

void fun2(int x) {
    ENTER_FN();
    fun3(x);
    EXIT_FN();
}

void fun3(int x) {
    std::cout<<x<<std::endl;
    ENTER_FN();
    // Print the backtrace here to see the stack before exiting
    backtrace.printBacktrace();
    EXIT_FN();
}

int main() {
    ENTER_FN();
    fun1(2);
    EXIT_FN();

    return 0;
}
