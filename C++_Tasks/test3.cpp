/*#include <iostream>
#include <vector>

// Define a simple struct for demonstration
struct Data {
    int x;
    int y;
};

// Template function to print elements of a container
template <typename T>
void print(const T& data) {
    for (const auto& item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Trivial data types
    int x = 0;        // Copy initialization
    int x2{};         // Value initialization (zero-initialization)
    int x3(0);        // Direct initialization

    // Default value (uninitialized)
    int value;        // Uninitialized
    int value2{};     // Zero initialization

    // std::cout output
    std::cout << "x3: " << x3 << std::endl;
    std::cout << "value (uninitialized): " << value << std::endl; // Undefined behavior if accessed
    std::cout << "value2: " << value2 << std::endl;  // Guaranteed to be 0

    // User-defined data types
    Data d;     // Uniform initialization
    Data d2{};        // Zero-initialization

    // Output user-defined data types
    std::cout << "d.x: " << d.x << std::endl;
    std::cout << "d2.x: " << d2.x << std::endl;
    std::cout << "d.y: " << d.y << std::endl;
    std::cout << "d2.y: " << d2.y << std::endl;

    // Effect with vectors
    std::vector<int> v(12, 3);  // Vector of size 12, each element initialized to 3
    std::vector<int> v2{12, 3}; // Vector of 2 elements with values 12 and 3

    // Print vectors using the template function
    print(v);
    print(v2);

    // Narrow conversion
    float decimal = 3.14;
    int number = decimal;               // Implicit cast: float to int
    std::cout << "Implicit cast: " << number << std::endl;

    // Static cast for narrowing conversion
    int number2 { static_cast<int>(decimal)}; // Narrowing conversion using static_cast
    std::cout << "Static cast: " << number2 << std::endl;

    return 0;
}
*/
/*#include <iostream>

enum class Traffic {
    RED,
    YELLOW,
    GREEN
};

enum class Teams {
    RED,
    MADRID,  // 1
    EGYPT    // 2
};

// Overloading the ostream operator for Traffic enum
std::ostream &operator<<(std::ostream &os, const Traffic &obj) {
    switch (obj) {
        case Traffic::RED:
            os << "Red";
            break;
        case Traffic::YELLOW:
            os << "Yellow";
            break;
        case Traffic::GREEN:
            os << "Green";
            break;
    }
    return os;
}

// Overloading the ostream operator for Teams enum
std::ostream &operator<<(std::ostream &os, const Teams &obj) {
    switch (obj) {
        case Teams::RED:
            os << "Red";
            break;
        case Teams::MADRID:
            os << "Madrid";
            break;
        case Teams::EGYPT:
            os << "Egypt";
            break;
    }
    return os;
}

// Function that takes Traffic enum and prints the corresponding color
void fun(Traffic value) {
    switch (value) {
        case Traffic::RED:
            std::cout << "Red" << std::endl;
            break;
        case Traffic::YELLOW:
            std::cout << "Yellow" << std::endl;
            break;
        case Traffic::GREEN:
            std::cout << "Green" << std::endl;
            break;
        default:
            std::cout << "Not handled in switch" << std::endl;
            break;
    }
}

// Function that takes Teams enum and prints the corresponding team
void fun(Teams value) {
    switch (value) {
        case Teams::RED:
            std::cout << "Red" << std::endl;
            break;
        case Teams::MADRID:
            std::cout << "Madrid" << std::endl;
            break;
        case Teams::EGYPT:
            std::cout << "Egypt" << std::endl;
            break;
        default:
            std::cout << "Not handled in switch" << std::endl;
            break;
    }
}

// Test enum class
enum class Test {
    success,
    fail
};

int main() {
    Traffic signal = Traffic::RED;
    Teams team = Teams::RED;
    
    fun(signal);  // Output: Red
    fun(team);  // Output: Red
    
    std::cout << "Current traffic signal: " << signal << std::endl;  // Output: Red
    std::cout << "Current team: " << team << std::endl;  // Output: Red

    return 0;
}
*/
/*#include <iostream>
#include <cstring>  
struct myData {
    int ID;
    char name[100];  
    // Default constructor
    myData() {
        ID = 0;  // Initialize ID with a default value
        std::cout << "Constructor called" << std::endl;
        strcpy(name, "default");  // Initialize name with a default value
    }
    // Destructor
    ~myData() {
        std::cout << "Destructor called" << std::endl;
    }
    void setter(int id, const char* n) {
        ID = id;
        strcpy(name, n);  
    }
};

int main() {
    myData data;  
    data.setter(10, "Moatasem");
    std::cout << "ID: " << data.ID << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0; 
}*/
/*#include <iostream>

struct myData {
    int ID;
    char value[100];  // Fixed-length array to store value

    // Constructor to initialize ID
    myData(int v) : ID(v) {}

    // Function to set the value of ID
    void fun(int v) {
        ID = v;
    }
};

// Static object (will be in .data or .bss, depending on initialization)
static myData obj(1);  // This object will be placed in the .data section

int main() {
    // Local object (will be in the stack)
    myData data2(3);  // This object will be on the stack
    
    // Output the size of the objects
    std::cout << "Size of obj: " << sizeof(obj) << std::endl;
    std::cout << "Size of data2: " << sizeof(data2) << std::endl;

    // Modifying the ID of data2
    data2.fun(3);

    // Output the ID values to verify correctness
    std::cout << "ID of obj: " << obj.ID << std::endl;
    std::cout << "ID of data2: " << data2.ID << std::endl;

    return EXIT_SUCCESS;
}*/
/*#include <iostream>
#include <cstring>
class myData {
    private:
    int ID;
    char value[100]; 
    public:
    myData(){
        ID = 0;
        std::cout << "Constructor called" << std::endl;
        strcpy(value, "default");
    }
    ~myData(){
        std::cout << "Destructor called" << std::endl;
    }
    void print();
};
void myData::print() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Value: " << value << std::endl;
}
int main() {
    myData data;
    data.print();
    std::cout<<"Hallo World"<<std::endl;
    return 0;
}*/
