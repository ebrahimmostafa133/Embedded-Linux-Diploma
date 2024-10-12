//---------  lec 11,12 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>
//---------------------- Task3 ----------------------
/*
Searching for
1- final
2- std::bind
3-template hpp
4-stringstream
5-chrono timers
6- random numbers
*/

// Final class
class Calculator final {
public:
    // Template function to add two numbers
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }

    // Function to print the sum using stringstream
    template <typename T>
    std::string printSum(T a, T b) {
        std::stringstream ss;
        ss << "Sum: " << add(a, b);
        return ss.str();
    }
};

//---------------------- Task4 ----------------------
/*
C++17
1-variant
2-optional
3-any
*/
// Define a variant type that can hold either int, double, or std::string
using VariantType = std::variant<int, double, std::string>;

// Function to demonstrate std::variant
void printVariant(const VariantType& var) {
    std::visit([](const auto& value) {
        std::cout << "Variant holds: " << value << std::endl;
    }, var);
}

// Function to demonstrate std::optional
std::optional<int> findValue(int key) {
    if (key % 2 == 0) {
        return key; // Return a value if the key is even
    }
    return std::nullopt; // Return empty if the key is odd
}

// Function to demonstrate std::any
void processAny(const std::any& data) {
    try {
        if (data.type() == typeid(int)) {
            std::cout << "Any holds an int: " << std::any_cast<int>(data) << std::endl;
        } else if (data.type() == typeid(std::string)) {
            std::cout << "Any holds a string: " << std::any_cast<std::string>(data) << std::endl;
        } else {
            std::cout << "Unknown type in any" << std::endl;
        }
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Bad any cast: " << e.what() << std::endl;
    }
}
int main() {
     // Using std::variant
    VariantType varInt = 42;
    VariantType varDouble = 3.14;
    VariantType varString = std::string("Hello, C++17!");

    std::cout << "Demonstrating std::variant:" << std::endl;
    printVariant(varInt);
    printVariant(varDouble);
    printVariant(varString);

    // Using std::optional
    std::cout << "\nDemonstrating std::optional:" << std::endl;
    for (int key = 0; key < 5; ++key) {
        auto value = findValue(key);
        if (value) {
            std::cout << "Found value for key " << key << ": " << *value << std::endl;
        } else {
            std::cout << "No value found for key " << key << std::endl;
        }
    }

    // Using std::any
    std::cout << "\nDemonstrating std::any:" << std::endl;
    std::any data1 = 100; // Holds an int
    std::any data2 = std::string("C++17 is cool!"); // Holds a string

    processAny(data1);
    processAny(data2);
    //----------------------------------------------------------------
    // Create a Calculator instance
    Calculator calc;

    // Bind the printSum function
    auto boundFunc = std::bind(&Calculator::printSum<int>, &calc, std::placeholders::_1, 10);

    // Random number generation
    std::random_device rd;                     // Random number generator
    std::mt19937 gen(rd());                    // Mersenne Twister engine
    std::uniform_int_distribution<> dis(1, 100); // Uniform distribution

    // Timing the execution
    auto start = std::chrono::high_resolution_clock::now();

    // Generate random numbers and print their sums with 10
    for (int n = 0; n < 5; ++n) {
        int randomNum = dis(gen);
        std::string result = boundFunc(randomNum);
        std::cout << result << std::endl; // Output: Sum: <randomNum + 10>
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    return 0;
}