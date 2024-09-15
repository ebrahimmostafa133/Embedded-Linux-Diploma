/*
#include <iostream>
int main() {
    // Define a 4-byte integer (32-bit integer)
    int arr[1] = { 0x12345678 }; // This is a 4-byte integer

    // Print the original integer value
    std::cout << "Original integer value: 0x" << std::hex << arr[0] <<
std::endl;

    // Access the first byte using casting
    unsigned char* firstByte = reinterpret_cast<unsigned char*>(arr);

    // Print the first byte
    std::cout << "First byte: 0x" << std::hex << static_cast<int>(*firstByte) <<
std::endl;

    return 0;
}
*/
/*
// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;  // Print a new line at the end
}

    // Initialize the array with 5 elements
    int numbers[] = {-1, 2, -3, -4, 5,6,8,9,9,10,11,12,13,};

    // Calculate the size of the array
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Print the array
    printArray(numbers, size);

*/
/*
    int num2 = 42;
    double pi = 3.14159265358979323846;
    double num3 = 123.456789;

    // Printing values with formatting
    std::cout << "Number: " << std::setw(6) << num2 << std::endl;
    std::cout << "Pi: " << std::setprecision(6) << pi << std::endl;
    std::cout << "Number: " << num3 << std::endl;

    // Printing in different number bases
    int num = 42;
    std::cout << "Hex: " << std::hex << num << std::endl;
    std::cout << "Oct: " << std::oct << num << std::endl;
    std::cout << "Dec: " << std::dec << num << std::endl;

    // Using scientific notation
    std::cout << std::scientific << "Scientific Pi: " << pi << std::endl;

*/
/*
    int main() {
    int choice;

    // Display menu
    std::cout << "Menu:\n";
    std::cout << "1. Print Hello\n";
    std::cout << "2. Print World\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Handle menu choices
    switch (choice) {
        case 1:
            std::cout << "Hello" << std::endl;
            break;
        case 2:
            std::cout << "World" << std::endl;
            break;
        case 3:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }

    return 0;
}

*/
/*
// Function to print a message
void printMessage(const std::string& message = "Hello, World!") {
    std::cout << message << std::endl;
}

int main() {
    // Prints default message
    printMessage();

    // Prints custom message
    printMessage("Hi there!");

    return 0;
}


*/
/*
#include <iostream>

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to multiply two doubles (overloaded function)
double multiply(double a, double b) {
    return a * b;
}

int main() {
    // Calling multiply for integers
    int result1 = multiply(3, 4);
    
    // Calling multiply for doubles
    double result2 = multiply(2.5, 3.0);

    // Output the results
    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}

*/
/*
#include <iostream>

// Function declarations
void fun(int x, int y);
void fun(int x, float y = 2.0);

void fun(int x, int y) {
    std::cout << x << " " << y << std::endl;
}

void fun(int x, float y) {
    std::cout << "hello float" << std::endl;
}

int main() {
    fun(2);      // Calls void fun(int x, float y) because float is the default
    fun(2, 3);   // Calls void fun(int x, int y)
    return 0;
}

*/
/*
#include <iostream>

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};  // Define and initialize the array
    int size = sizeof(numbers) / sizeof(numbers[0]);  // Calculate the size of the array

    printArray(numbers, size);  // Call the function to print the array

    return 0;
}

*/
/*
#include <iostream>

int main() {
    int x = 10;
    int &refTox = x;    // Reference to x
    int *ptrTox = &x;   // Pointer to x

    std::cout << "Initial value of x: " << x << std::endl;
    std::cout << "Value via refTox: " << refTox << std::endl;
    std::cout << "Value via ptrTox: " << *ptrTox << std::endl;

    refTox = 20; // Changes the value of x
    std::cout << "Value of x after refTox = 20: " << x << std::endl;

    *ptrTox = 30; // Changes the value of x
    std::cout << "Value of x after *ptrTox = 30: " << x << std::endl;

    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <initializer_list>

int main() {
    int var1 = 10;               // Simple integer variable
    double var2 = 10.5;          // Double variable
    char var3 = 'a';             // Character variable
    const char* var4 = "const char*"; // Pointer to a constant character string
    std::string var5 = "std::string"; // std::string variable

    const int x = 42;           // Constant integer

    auto var6 = x;              // `var6` is deduced as `const int`
    const auto var7 = x;        // `var7` is deduced as `const int`
    auto &var8 = x;             // `var8` is a reference to `const int`
    const auto *ptr = &x;       // `ptr` is a pointer to `const int`

    // Using std::initializer_list
    std::initializer_list<int> lst = {1, 2, 3, 4}; // Correct use of initializer list

    // Print the values to verify
    std::cout << "var1: " << var1 << std::endl; //10
    std::cout << "var2: " << var2 << std::endl; //10.5
    std::cout << "var3: " << var3 << std::endl; //a
    std::cout << "var4: " << var4 << std::endl; //const char*
    std::cout << "var5: " << var5 << std::endl; //std::string
    std::cout << "x: " << x << std::endl;   //42
    std::cout << "var6: " << var6 << std::endl; //42
    std::cout << "var7: " << var7 << std::endl; //42
    std::cout << "var8: " << var8 << std::endl; //42
    std::cout << "ptr: " << *ptr << std::endl;  //42

    // Print initializer list elements
    std::cout << "lst: ";
    for (const auto& elem : lst) {
        std::cout << elem << " "; //1 2 3 4
    }
    std::cout << std::endl;

    return 0;
}
*/
/*
#include <iostream>

// Base class with a virtual destructor for proper cleanup
class Base {
public:
    virtual ~Base() = default;  // Virtual destructor
    virtual void show() const { std::cout << "Base class" << std::endl; }
};

// Derived class inheriting from Base
class Derived : public Base {
public:
    void show() const override { std::cout << "Derived class" << std::endl; }
};

// Another class inheriting from Base
class AnotherClass : public Base {
public:
    void show() const override { std::cout << "AnotherClass class" << std::endl; }
};

int main() {
    Base *basePtr = new Derived();       // Base pointer to Derived object
    Base *anotherBasePtr = new AnotherClass(); // Base pointer to AnotherClass object

    // Using dynamic_cast to safely cast to Derived
    Derived *derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        std::cout << "Successfully cast to Derived* using dynamic_cast." << std::endl;
        derivedPtr->show(); // Output: Derived class
    } else {
        std::cout << "Failed to cast to Derived* using dynamic_cast." << std::endl;
    }

    // Attempting to cast to Derived* from anotherBasePtr (should fail)
    derivedPtr = dynamic_cast<Derived*>(anotherBasePtr);
    if (derivedPtr) {
        std::cout << "Successfully cast to Derived* using dynamic_cast." << std::endl;
        derivedPtr->show();
    } else {
        std::cout << "Failed to cast to Derived* using dynamic_cast." << std::endl;
    }

    // Clean up
    delete basePtr;
    delete anotherBasePtr;

    return 0;
}

*/





