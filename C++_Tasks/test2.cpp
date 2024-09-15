/*#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int offset;
    std::cin >> offset;

    std::vector<int> v = {10, 12, 30, 1, 2, 0, 31};

    // Sort the vector using a lambda function with an offset
    std::sort(v.begin(), v.end(), [offset](int num1, int num2) {
        return (num1 + offset) < (num2 + offset);
    });

    // Print the sorted vector
    std::for_each(v.begin(), v.end(), [](int num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;

    return 0;
}*/
/*#include <iostream>

int main() {
    int temp = 10; // Variable in main

    // Lambda expression with capture by value and mutable keyword
    [temp]() mutable {
        temp = 100; // Modify the captured copy of temp
        std::cout << "Inside lambda: " << temp << std::endl; // Outputs 100
    }(); // Immediately invoke the lambda

    // Outputs the outer 'temp' value
    std::cout << "Outside lambda: " << temp << std::endl; // Outputs 10

    return 0;
}
*/
/*#include <iostream>

int main() {
    int temp = 10;  // Initialize temp
    int value = 12; // Initialize value

    // Lambda expression capturing temp by reference
    [&temp] (int number)  {
        temp = 100; // Modify the captured reference
        std::cout << temp << std::endl; // Outputs 100
    }(3); // Immediately invoke the lambda

    // Output the modified temp from the main scope
    std::cout << temp << std::endl; // Outputs 100

    // Lambda expression capturing temp by reference and value by value
    [&temp, value] (int number)  {
        temp = 200; // Modify the captured reference
        std::cout << value + temp << std::endl; // Outputs 212
    }(3); // Immediately invoke the lambda

    // Output the modified temp from the main scope
    std::cout << temp << std::endl; // Outputs 200

    return 0;
}*/
/*#include <iostream>
#include <typeinfo>
int main() {
    //int x = 100;
    // Lambda function that captures x by value and prints a message
    auto pf=[](auto num1,auto num2){return num1+num2;};    
    std::cout <<typeid(pf(1, 2)).name()<<std::endl;
    std::cout <<typeid(pf(1.2, 2.5)).name() <<std::endl;
    return 0;
}*/
/*#include <iostream>
int main(){
    int temp=10;
    [&v =temp,x=100](){
        std::cout <<v<<std::endl;
        std::cout <<x<<std::endl;
        v=200;
    }();
    std::cout<<temp<<std::endl; 

    return 0;
}*/
/*#include <iostream>
#include <array>
#include <algorithm>

int main() {
    int sum = 0;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::for_each(arr.begin(), arr.end(), [&sum](int &n) {
        sum += n;
    });

    std::cout << "Sum of array: " << sum << std::endl;

    return 0;
}
*/
/*include <iostream>
int main() {
[](){ std:: cout << "Hello, World!" << std::endl; }();
[](){ std::cout << "Hello, World!" << std::endl; }();
return 0;
}

*/
/*#include <iostream>

constexpr int sum(int x, int y) {
    return x + y;  // This is a valid constexpr function since it returns a simple expression
}

int main() {
    constexpr int e = 10;  // Define a constant expression
    constexpr int result = sum(e, 20);  // Call the sum function with constexpr arguments
    std::cout << result << std::endl;  // Output the result
    return 0;
}*/

