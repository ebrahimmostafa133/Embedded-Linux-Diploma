// author: Ebrahim Mostafa
//    queue file
#include <iostream>
#include <queue>

int main() {
    // 1. Using std::queue
    std::queue<int> myQueue;

    // queue::push
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    std::cout << "Queue after pushing elements: ";
    std::queue<int> tempQueue = myQueue; // Use a temp queue to print without modifying original
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    // queue::front and queue::back
    std::cout << "Front element using front(): " << myQueue.front() << std::endl;
    std::cout << "Back element using back(): " << myQueue.back() << std::endl;

    // queue::pop
    myQueue.pop();
    std::cout << "Queue after pop(): ";
    tempQueue = myQueue; // Reset the temp queue
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    // queue::emplace
    myQueue.emplace(40);
    std::cout << "Queue after emplace(40): ";
    tempQueue = myQueue;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    // queue::size and queue::empty
    std::cout << "Size of queue: " << myQueue.size() << std::endl;
    std::cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    // queue::swap
    std::queue<int> anotherQueue;
    anotherQueue.push(100);
    anotherQueue.push(200);
    myQueue.swap(anotherQueue);
    
    std::cout << "Queue after swapping with another queue: ";
    tempQueue = myQueue;
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    // 2. Using std::priority_queue
    std::priority_queue<int> myPriorityQueue;

    // priority_queue::push
    myPriorityQueue.push(50);
    myPriorityQueue.push(10);
    myPriorityQueue.push(40);
    
    std::cout << "Priority queue after pushing elements: ";
    std::priority_queue<int> tempPriorityQueue = myPriorityQueue;
    while (!tempPriorityQueue.empty()) {
        std::cout << tempPriorityQueue.top() << " ";  // priority_queue::top gives highest element
        tempPriorityQueue.pop();
    }
    std::cout << std::endl;

    // priority_queue::pop
    myPriorityQueue.pop();
    std::cout << "Priority queue after pop(): ";
    tempPriorityQueue = myPriorityQueue;
    while (!tempPriorityQueue.empty()) {
        std::cout << tempPriorityQueue.top() << " ";
        tempPriorityQueue.pop();
    }
    std::cout << std::endl;

    // priority_queue::emplace
    myPriorityQueue.emplace(60);
    std::cout << "Priority queue after emplace(60): ";
    tempPriorityQueue = myPriorityQueue;
    while (!tempPriorityQueue.empty()) {
        std::cout << tempPriorityQueue.top() << " ";
        tempPriorityQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
