// author: Ebrahim Mostafa
//  List file

#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>

int main() {
    // 1. Using std::list
    std::list<int> myList = {10, 20, 30, 40};

    // list::push_back, list::push_front
    myList.push_back(50);
    myList.push_front(5);
    std::cout << "List after push_back(50) and push_front(5): ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    // list::front and list::back
    std::cout << "Front element: " << myList.front() << std::endl;
    std::cout << "Back element: " << myList.back() << std::endl;

    // list::insert and list::erase
    auto it = myList.begin();
    std::advance(it, 2);
    myList.insert(it, 15); // Insert 15 at the 2nd position
    std::cout << "After insert(15): ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;
    
    it = myList.erase(it); // Erase the 2nd element
    std::cout << "After erase: ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    // list::emplace_front, list::emplace_back
    myList.emplace_front(2);
    myList.emplace_back(60);
    std::cout << "After emplace_front(2) and emplace_back(60): ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    // list::pop_back and list::pop_front
    myList.pop_back();
    myList.pop_front();
    std::cout << "After pop_back() and pop_front(): ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    // list::sort, list::reverse, and list::unique
    myList.sort();
    std::cout << "Sorted list: ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;
    
    myList.reverse();
    std::cout << "Reversed list: ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    myList.push_back(30);
    myList.unique(); // Removes consecutive duplicates
    std::cout << "After unique(): ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    // list::swap
    std::list<int> anotherList = {100, 200, 300};
    myList.swap(anotherList); // Swap contents with anotherList
    std::cout << "After swapping with anotherList: ";
    for (int &x : myList) std::cout << x << " ";
    std::cout << std::endl;

    // 2. Using std::forward_list
    std::forward_list<int> myFList = {10, 20, 30, 40};

    // forward_list::push_front, forward_list::emplace_front
    myFList.push_front(5);
    myFList.emplace_front(2);
    std::cout << "Forward List after push_front(5) and emplace_front(2): ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    // forward_list::insert_after and forward_list::erase_after
    auto fit = myFList.before_begin();
    fit = myFList.insert_after(fit, 15); // Insert 15 after before_begin
    std::cout << "After insert_after(15): ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    fit = myFList.erase_after(fit); // Erase the element after the first
    std::cout << "After erase_after(): ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    // forward_list::sort and forward_list::reverse
    myFList.sort();
    std::cout << "Sorted forward list: ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    myFList.reverse();
    std::cout << "Reversed forward list: ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    // forward_list::unique
    myFList.push_front(30);
    myFList.unique(); // Removes consecutive duplicates
    std::cout << "After unique(): ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    // forward_list::merge
    std::forward_list<int> anotherFList = {100, 200, 300};
    myFList.merge(anotherFList); // Merges two sorted lists
    std::cout << "After merge with another forward list: ";
    for (int &x : myFList) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
