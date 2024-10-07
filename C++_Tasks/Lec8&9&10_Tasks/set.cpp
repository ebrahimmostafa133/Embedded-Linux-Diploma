// author: Ebrahim Mostafa
//    set file
#include <iostream>
#include <set>

int main() {
    // 1. Using std::set
    std::set<int> mySet;

    // set::insert
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // Duplicates are not allowed in std::set
    mySet.insert(30);
    
    std::cout << "Set after insertions: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";  // Elements are unique and ordered
    }
    std::cout << std::endl;

    // set::find
    auto it = mySet.find(20);
    if (it != mySet.end()) {
        std::cout << "Element 20 found in the set." << std::endl;
    } else {
        std::cout << "Element 20 not found in the set." << std::endl;
    }

    // set::erase
    mySet.erase(10);
    std::cout << "Set after erasing 10: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // set::emplace
    mySet.emplace(40);
    std::cout << "Set after emplace(40): ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // set::size and set::empty
    std::cout << "Size of the set: " << mySet.size() << std::endl;
    std::cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl;

    // set::swap
    std::set<int> anotherSet = {50, 60, 70};
    mySet.swap(anotherSet);
    
    std::cout << "Set after swapping with another set: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // set::lower_bound and set::upper_bound
    auto lb = anotherSet.lower_bound(60); // First element not less than 60
    auto ub = anotherSet.upper_bound(60); // First element greater than 60
    std::cout << "Lower bound of 60 in anotherSet: " << *lb << std::endl;
    std::cout << "Upper bound of 60 in anotherSet: " << (ub != anotherSet.end() ? std::to_string(*ub) : "None") << std::endl;

    // 2. Using std::multiset
    std::multiset<int> myMultiSet;

    // multiset::insert
    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(10);  // Duplicates are allowed in std::multiset
    myMultiSet.insert(30);
    
    std::cout << "Multiset after insertions: ";
    for (const auto& elem : myMultiSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // multiset::count
    std::cout << "Count of element 10 in multiset: " << myMultiSet.count(10) << std::endl;

    // multiset::equal_range
    auto range = myMultiSet.equal_range(10);
    std::cout << "Elements with key 10 in multiset: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // multiset::erase
    myMultiSet.erase(10);
    std::cout << "Multiset after erasing all 10s: ";
    for (const auto& elem : myMultiSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
