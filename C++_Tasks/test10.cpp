#include <bits/stdc++.h>
// Function prototypes for state handlers
bool redHandler();
bool greenHandler();
bool yellowHandler();


bool redHandler() {
    std::cout << "Red Handler" << std::endl;
    return true; // Could implement more complex behavior if desired
}

bool greenHandler() {
    std::cout << "Green Handler" << std::endl;
    return true; // Could implement more complex behavior if desired
}

bool yellowHandler() {
    std::cout << "Yellow Handler" << std::endl;
    return true; // Could implement more complex behavior if desired
}
enum class TrafficLight { Red, Green, Yellow };
int main(){
    std::map<int, std::string> myMap;
    // Insert key-value pairs
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    // Print elements using range-based for loop
    std::cout << "Elements in the map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
    // Find an element by key
    int keyToFind = 2;
    auto it = myMap.find(keyToFind);
    if (it != myMap.end()) {
        std::cout << "Value for key " << keyToFind << " is " << it->second << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found." << std::endl;
    }
    // Check if a key exists using count()
    bool keyExists = myMap.count(4) > 0;
    std::cout << "Key 4 exists: " << (keyExists ? "Yes" : "No") << std::endl;
    //----------------------------------------------------------------
    std::multimap<std::string, std::string> shoppingList;
    // Insert key-value pairs (category, item)
    shoppingList.insert({"fruits", "orange"});
    shoppingList.insert({"fruits", "apple"});
    shoppingList.insert({"vegetables", "tomato"});
    shoppingList.insert({"vegetables", "potato"});
    // Output the multimap contents
    std::cout << "Shopping list using std::multimap:" << std::endl;
    for (const auto& pair : shoppingList) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    // Find all items in the 'fruits' category
    std::cout << "\nItems in the 'fruits' category:" << std::endl;
    auto range = shoppingList.equal_range("fruits");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << std::endl;
    }
    //----------------------------------------------------------------
    // State machine definition: <trigger, next state>
    std::map<TrafficLight, std::pair<TrafficLight, std::function<bool()>>> stateMachine = {
        {TrafficLight::Red, {TrafficLight::Green, redHandler}},
        {TrafficLight::Green, {TrafficLight::Yellow, greenHandler}},
        {TrafficLight::Yellow, {TrafficLight::Red, yellowHandler}}
    };
    TrafficLight currentState = TrafficLight::Red;
    int cnt = 0;

    while (cnt++ < 3) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Current State: " << static_cast<int>(currentState) << std::endl;
        
        // Call the handler function for the current state
        stateMachine[currentState].second();

        // Transition to the next state
        currentState = stateMachine[currentState].first;
    }
    //----------------------------------------------------------------
    // Define two vectors
    /*
    std::vector<int> v{1, 2, 3, 4, 5, 12, 14, 2};
    std::vector<int> v2{1, 2, 3, 6, 5, 12, 14, 2};

    // Check if all elements are greater than 0
    bool all_positive = std::all_of(v.begin(), v.end(), [](int i) { return i > 0; });
    std::cout << "All elements are positive: " << all_positive << std::endl;

    // Check if any element is greater than 10
    bool any_greater_than_10 = std::any_of(v.begin(), v.end(), [](int i) { return i > 10; });
    std::cout << "Any element greater than 10: " << any_greater_than_10 << std::endl;

    // Check if none of the elements are negative
    bool none_negative = std::none_of(v.begin(), v.end(), [](int i) { return i < 0; });
    std::cout << "No negative elements: " << none_negative << std::endl;

    // Find the first mismatch between the two vectors
    auto mismatch_pair = std::mismatch(v.begin(), v.end(), v2.begin());
    if (mismatch_pair.first != v.end()) {
        std::cout << "First mismatch at index: " 
                  << std::distance(v.begin(), mismatch_pair.first) 
                  << ", values: " << *mismatch_pair.first << " and " << *mismatch_pair.second 
                  << std::endl;
    } else {
        std::cout << "No mismatch found." << std::endl;
    }

    // Count the occurrences of the number 2
    int count_of_2 = std::count(v.begin(), v.end(), 2);
    std::cout << "Number of occurrences of 2: " << count_of_2 << std::endl;

    // Count the even numbers
    int even_count = std::count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
    std::cout << "Number of even numbers: " << even_count << std::endl;

    // Apply a transformation (multiply each element by 2)
    std::vector<int> transformed_v(v.size());
    std::transform(v.begin(), v.end(), transformed_v.begin(), [](int i) { return i * 2; });
    std::cout << "Transformed vector (each element * 2): ";
    for (int i : transformed_v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    */
   
    /*
    // Original vector
    std::vector<int> v{1, 2, 3, 4, 5, 12, 14, 2};

    // 1. Copy elements that satisfy a condition (even numbers)
    std::vector<int> copy_v(v.size());
    auto it_copy = std::copy_if(v.begin(), v.end(), copy_v.begin(), [](int i) { return i % 2 == 0; });
    copy_v.resize(std::distance(copy_v.begin(), it_copy));
    std::cout << "Copied even numbers: ";
    for (int i : copy_v) std::cout << i << " ";
    std::cout << std::endl;

    // 2. Copy the first 3 elements
    std::vector<int> copy_n_v(3); 
    std::copy_n(v.begin(), 3, copy_n_v.begin());
    std::cout << "First 3 elements copied: ";
    for (int i : copy_n_v) std::cout << i << " ";
    std::cout << std::endl;

    // 3. Move elements from one vector to another
    std::vector<int> move_v(v.size());
    std::move(v.begin(), v.end(), move_v.begin());
    std::cout << "Moved vector: ";
    for (int i : move_v) std::cout << i << " ";
    std::cout << std::endl;

    // 4. Fill the vector with a value (e.g., 10)
    std::vector<int> fill_v(v.size());
    std::fill(fill_v.begin(), fill_v.end(), 10);
    std::cout << "Filled vector with 10: ";
    for (int i : fill_v) std::cout << i << " ";
    std::cout << std::endl;

    // 5. Fill first n elements with a value (e.g., fill 3 elements with 10)
    std::vector<int> fill_n_v(v.size());
    std::fill_n(fill_n_v.begin(), 3, 10);
    std::cout << "First 3 elements filled with 10: ";
    for (int i : fill_n_v) std::cout << i << " ";
    std::cout << std::endl;

    // 6. Transform (multiply each element by 2)
    std::vector<int> transform_v(v.size());
    std::transform(v.begin(), v.end(), transform_v.begin(), [](int i) { return i * 2; });
    std::cout << "Transformed vector (each element * 2): ";
    for (int i : transform_v) std::cout << i << " ";
    std::cout << std::endl;

    // 7. Generate a sequence of values (starting from 1)
    std::vector<int> generate_v(v.size());
    int value = 1;
    std::generate(generate_v.begin(), generate_v.end(), [&value]() { return value++; });
    std::cout << "Generated sequence: ";
    for (int i : generate_v) std::cout << i << " ";
    std::cout << std::endl;

    // 8. Remove all occurrences of the value 3
    std::vector<int> remove_v(v);
    auto it_remove = std::remove(remove_v.begin(), remove_v.end(), 3);
    remove_v.resize(std::distance(remove_v.begin(), it_remove));
    std::cout << "Vector after removing 3s: ";
    for (int i : remove_v) std::cout << i << " ";
    std::cout << std::endl;

    // 9. Remove copy (copy all elements except 3)
    std::vector<int> remove_copy_v(v.size());
    auto it_remove_copy = std::remove_copy_if(v.begin(), v.end(), remove_copy_v.begin(), [](int i) { return i == 3; });
    remove_copy_v.resize(std::distance(remove_copy_v.begin(), it_remove_copy));
    std::cout << "Copied vector without 3s: ";
    for (int i : remove_copy_v) std::cout << i << " ";
    std::cout << std::endl;

    // 10. Replace all occurrences of 3 with 10
    std::vector<int> replace_v(v);
    std::replace(replace_v.begin(), replace_v.end(), 3, 10);
    std::cout << "Vector after replacing 3s with 10: ";
    for (int i : replace_v) std::cout << i << " ";
    std::cout << std::endl;
    */
    std::vector<int> v = {9, 0, 4, 1, 8, 3, 8, 2, 9};
    std::vector<int> w = {1, 4, 6, 5};

    // std::find: Finds the first occurrence of a value
    auto it1 = std::find(v.begin(), v.end(), 8);
    if (it1 != v.end())
        std::cout << "First occurrence of 8: " << *it1 << std::endl;

    // std::find_if: Finds the first element greater than or equal to 6
    auto it2 = std::find_if(v.begin(), v.end(), [](int i) { return i >= 6; });
    if (it2 != v.end())
        std::cout << "First element >= 6: " << *it2 << std::endl;

    // std::find_if_not: Finds the first element less than or equal to 2
    auto it3 = std::find_if_not(v.begin(), v.end(), [](int i) { return i > 2; });
    if (it3 != v.end())
        std::cout << "First element <= 2: " << *it3 << std::endl;

    // std::adjacent_find: Finds the first occurrence of two consecutive equal elements
    auto it4 = std::adjacent_find(v.begin(), v.end());
    if (it4 != v.end())
        std::cout << "First occurrence of consecutive equal elements: " << *it4 << std::endl;

    // std::search_n: Finds the first occurrence of two consecutive elements equal to 8
    auto it5 = std::search_n(v.begin(), v.end(), 2, 8);
    if (it5 != v.end())
        std::cout << "First occurrence of two consecutive 8s: " << *it5 << std::endl;

    // std::find_first_of: Finds the first match of any element from another range
    auto it6 = std::find_first_of(v.begin(), v.end(), w.begin(), w.end());
    if (it6 != v.end())
        std::cout << "First matching element from another range: " << *it6 << std::endl;

    // std::search: Finds the first occurrence of a subrange (in this case {4, 6, 5})
    auto it7 = std::search(v.begin(), v.end(), w.begin() + 1, w.end());
    if (it7 != v.end())
        std::cout << "First occurrence of subrange {4, 6, 5}: " << *it7 << std::endl;

    // std::find_end: Finds the last occurrence of a subrange (in this case {4, 6, 5})
    auto it8 = std::find_end(v.begin(), v.end(), w.begin() + 1, w.end());
    if (it8 != v.end())
        std::cout << "Last occurrence of subrange {4, 6, 5}: " << *it8 << std::endl;





    return 0;
}