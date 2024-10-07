// author: Ebrahim Mostafa
//    stack file

#include <iostream>
#include <stack>

int main() {
    // 1. Using std::stack
    std::stack<int> myStack;

    // stack::push
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    std::cout << "Stack after pushing elements: ";
    std::stack<int> temp = myStack; // Use a temp stack to print without modifying original
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // stack::top
    std::cout << "Top element using top(): " << myStack.top() << std::endl;

    // stack::pop
    myStack.pop();
    std::cout << "Stack after pop(): ";
    temp = myStack; // Reset the temp stack
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // stack::emplace
    myStack.emplace(40);
    std::cout << "Stack after emplace(40): ";
    temp = myStack;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // stack::size
    std::cout << "Size of stack: " << myStack.size() << std::endl;

    // stack::empty
    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    // stack::swap
    std::stack<int> anotherStack;
    anotherStack.push(100);
    anotherStack.push(200);
    myStack.swap(anotherStack);
    
    std::cout << "Stack after swapping with another stack: ";
    temp = myStack;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    return 0;
}
