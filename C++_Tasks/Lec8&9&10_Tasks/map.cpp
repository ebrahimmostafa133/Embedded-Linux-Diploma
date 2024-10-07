// author: Ebrahim Mostafa
//  map file

#include <iostream>
#include <map>

int main() {
    // 1. Using std::map
    std::map<int, std::string> myMap;

    // map::insert, map::operator[]
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap.insert({3, "Cherry"});
    
    std::cout << "Map after insertions: " << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // map::at
    std::cout << "Element with key 1 using at(): " << myMap.at(1) << std::endl;

    // map::find
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Element found with key 2: " << it->second << std::endl;
    }

    // map::erase
    myMap.erase(2);
    std::cout << "After erasing key 2: ";
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    // map::emplace and map::emplace_hint
    myMap.emplace(4, "Date");
    myMap.emplace_hint(myMap.end(), 5, "Elderberry");
    
    std::cout << "Map after emplace and emplace_hint: ";
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    // map::size and map::empty
    std::cout << "Size of the map: " << myMap.size() << std::endl;
    std::cout << "Is the map empty? " << (myMap.empty() ? "Yes" : "No") << std::endl;

    // map::swap
    std::map<int, std::string> anotherMap = {{6, "Fig"}, {7, "Grapes"}};
    myMap.swap(anotherMap);
    
    std::cout << "After swap, myMap: ";
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    // map::lower_bound and map::upper_bound
    auto lb = anotherMap.lower_bound(6); // First element not less than 6
    auto ub = anotherMap.upper_bound(6); // First element greater than 6
    std::cout << "Lower bound of 6 in anotherMap: " << lb->first << ": " << lb->second << std::endl;
    std::cout << "Upper bound of 6 in anotherMap: " << (ub != anotherMap.end() ? ub->first : -1) << std::endl;

    // 2. Using std::multimap
    std::multimap<int, std::string> myMultiMap;

    // multimap::insert
    myMultiMap.insert({1, "Apple"});
    myMultiMap.insert({1, "Apricot"});
    myMultiMap.insert({2, "Banana"});
    
    std::cout << "Multimap after insertions: " << std::endl;
    for (const auto& pair : myMultiMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // multimap::equal_range
    auto range = myMultiMap.equal_range(1);
    std::cout << "Elements with key 1 in multimap: " << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // multimap::erase
    myMultiMap.erase(1);
    std::cout << "Multimap after erasing key 1: ";
    for (const auto& pair : myMultiMap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}


