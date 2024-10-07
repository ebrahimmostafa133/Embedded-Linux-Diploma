// author: Ebrahim Mostafa
//    vector file
#include <iostream>
#include <vector>
#include <algorithm> // for swap and relational operators

int main() {
    // C++11: Initialize vector with initializer list
    std::vector<int> vec1 = {10, 20, 30, 40};
    
    // vector::at and vector::operator[]
    std::cout << "Element at index 2 using at(): " << vec1.at(2) << std::endl;
    std::cout << "Element at index 2 using operator[]: " << vec1[2] << std::endl;
    
    // vector::front and vector::back
    std::cout << "Front element: " << vec1.front() << std::endl;
    std::cout << "Back element: " << vec1.back() << std::endl;
    
    // vector::push_back and vector::pop_back
    vec1.push_back(50);
    std::cout << "After push_back(50): " << vec1.back() << std::endl;
    vec1.pop_back();
    std::cout << "After pop_back(): " << vec1.back() << std::endl;
    
    // vector::begin, vector::end, and vector::insert
    std::cout << "Inserting 15 at position 2..." << std::endl;
    vec1.insert(vec1.begin() + 1, 15);
    
    // Iterating using begin() and end()
    std::cout << "Elements of vec1: ";
    for(auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // vector::erase
    vec1.erase(vec1.begin() + 1); // Remove element at position 1
    std::cout << "After erase(): ";
    for(auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // vector::capacity, vector::size, vector::resize, and vector::reserve
    std::cout << "Capacity: " << vec1.capacity() << std::endl;
    std::cout << "Size: " << vec1.size() << std::endl;
    vec1.reserve(10); // Reserving space for 10 elements
    vec1.resize(6);   // Resizing to hold 6 elements
    std::cout << "After reserve(10) and resize(6): " << std::endl;
    std::cout << "Capacity: " << vec1.capacity() << std::endl;
    std::cout << "Size: " << vec1.size() << std::endl;

    // C++11: vector::shrink_to_fit
    vec1.shrink_to_fit();
    std::cout << "After shrink_to_fit(): Capacity: " << vec1.capacity() << std::endl;

    // C++11: vector::emplace and vector::emplace_back
    vec1.emplace(vec1.begin() + 2, 25);
    vec1.emplace_back(60);
    std::cout << "After emplace and emplace_back: ";
    for(const auto& elem : vec1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // vector::clear and vector::empty
    vec1.clear();
    std::cout << "After clear(): Is empty? " << (vec1.empty() ? "Yes" : "No") << std::endl;

    // vector::swap and non-member swap
    std::vector<int> vec2 = {1, 2, 3};
    std::vector<int> vec3 = {4, 5, 6};
    
    std::cout << "Before swap: vec2 = ";
    for(const auto& elem : vec2) std::cout << elem << " ";
    std::cout << ", vec3 = ";
    for(const auto& elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;

    vec2.swap(vec3);  // member swap function
    std::cout << "After member swap: vec2 = ";
    for(const auto& elem : vec2) std::cout << elem << " ";
    std::cout << ", vec3 = ";
    for(const auto& elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;

    std::swap(vec2, vec3); // non-member swap function
    std::cout << "After non-member swap: vec2 = ";
    for(const auto& elem : vec2) std::cout << elem << " ";
    std::cout << ", vec3 = ";
    for(const auto& elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;

    // C++11: vector::data
    int* dataPtr = vec2.data();
    std::cout << "First element using data(): " << *dataPtr << std::endl;

    // Relational operators (non-member overloads)
    std::cout << "Is vec2 == vec3? " << (vec2 == vec3 ? "Yes" : "No") << std::endl;
    std::cout << "Is vec2 < vec3? " << (vec2 < vec3 ? "Yes" : "No") << std::endl;

    return 0;
}

