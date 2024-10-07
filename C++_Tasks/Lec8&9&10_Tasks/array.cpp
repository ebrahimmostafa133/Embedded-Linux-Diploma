// author: Ebrahim Mostafa
//    <array>  --> Array header (header)

#include <iostream>
#include <array>
#include <tuple>  // For std::get, std::tuple_size

int main() {
    // Initialize a std::array of integers with size 5
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    // Access elements with at() (with bounds checking)
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;
    // Access elements with operator[] (no bounds checking)
    std::cout << "Element at index 3: " << arr[3] << std::endl;
    // Get the first and last element using front() and back()
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;
    // Check if the array is empty (it won't be, as std::array has a fixed size)
    std::cout << "Is array empty? " << std::boolalpha << arr.empty() << std::endl;
    // Get the size and max_size (which are the same for std::array)
    std::cout << "Size of array: " << arr.size() << std::endl;
    std::cout << "Max size of array: " << arr.max_size() << std::endl;
    // Fill the array with a single value
    arr.fill(100);
    std::cout << "Array after fill(100): ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // Access data pointer
    int* data_ptr = arr.data();
    std::cout << "First element via data(): " << *data_ptr << std::endl;
    // Using iterators
    std::cout << "Array elements using iterators: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Using reverse iterators
    std::cout << "Array elements in reverse order: ";
    for (auto rit = arr.rbegin(); rit != arr.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    // Non-member functions: std::get and tuple-like behavior
    std::array<std::string, 3> strArr = {"apple", "banana", "cherry"};
    std::cout << "First element of strArr (using std::get): " << std::get<0>(strArr) << std::endl;
    // Compile-time size information
    constexpr std::size_t arraySize = std::tuple_size<decltype(strArr)>::value;
    std::cout << "Size of strArr (using std::tuple_size): " << arraySize << std::endl;

    return 0;
}