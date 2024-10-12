#include<bits/stdc++.h>

class MycustomException: public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid input. Please enter a positive integer.";
    }
};
void fun3(){throw "Error";}
void fun2(){
    try{
        fun3();
    }catch(...) {
        throw;
    }
}
namespace mycontainer{
    namespace myvector{
        class vector{};
        void print(){std::cout<<"mycontainer::myvector::print()"<<std::endl;}
    }
}
class Data{
    int x;
    int y;
    public:
    Data(int a, int b):x(a),y(b){}
};
void fun(const std::unique_ptr<int>& temp){
    std::cout<<*temp<<std::endl;
}
class FileDeleter {
public:
    void operator()(FILE *file) const {
        if (file) {
            std::cout << "Closing file\n";
            fclose(file);
        }
    }
};

// 1- Basic template single argument
template <typename T>
T division(T x, T y) {
    return x / y;
}

// 2- Basic template with multiple arguments
template <typename T, typename U>
auto division(T x, U y) {
    return x / y;
}

// 3- Class template
template <typename T>
class container {
public:
    T value;
    
    // Constructor
    container(T val) : value(val) {}
    
    // Method to print the value
    void print() {
        std::cout << value << std::endl;
    }
};

// 4- Class template with standalone function template
template <typename T>
class container2 {
public:
    T value;

    // Constructor
    container2(T val) : value(val) { }

    // Template function to add a value of any type
    template <typename U>
    void add(U val) {
        value += val;  // Adds U to T, can be different types
    }

    // Method to print the value
    void print() {
        std::cout << value << std::endl;
    }
};

// 5- Explicit specialization (if needed)
template <>
class container<double> {
public:
    double value;

    container(double val) : value(val) { }

    void print() {
        std::cout << "Specialized container for double: " << value << std::endl;
    }
};
// 6- Primary template
template <typename T, typename U>
class array {
public:
    // Constructor for the primary template
    array(T t, U u) {
        std::cout << "Primary template" << std::endl;
    }
};

// 6- Partial specialization where both template parameters are of the same type (T)
template <typename T>
class array<T, T> {
public:
    // Constructor for the partial specialization
    array(T t, T u) {
        std::cout << "Partial specialization" << std::endl;
    }
};

// 7- Default template arguments
template <typename T, typename U = int>
class A {
public:
    T t;
    U u;

    // Constructor that takes two arguments, with U defaulting to int if not provided
    A(T t, U u = 0) : t(t), u(u) {}

    void print() const {
        std::cout << "T: " << t << ", U: " << u << std::endl;
    }
};

// 8- Constant expression template argument (size of array)
template <typename T, int Size>
class MyArray {
public:
    T data[Size];

    // Constructor to initialize the array elements
    MyArray() {
        for (int i = 0; i < Size; i++) {
            data[i] = i + 1;  // Just for demonstration, set elements to 1, 2, ..., Size
        }
    }

    // Function to print the array
    void print() const {
        for (int i = 0; i < Size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
// Base case: when there are no more arguments to process
void print() {
    std::cout << "End of print" << std::endl;
}

// Variadic template function to print arguments
template <typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << " ";  // Print the current argument
    std::cout << "Number of remaining arguments: " << sizeof...(args) << std::endl;

    // Recursively call print for the remaining arguments
    print(args...);  // Recursive call with the remaining arguments
}

int main()/*try*/{
    // Creating a pair
    std::pair<int, std::string> myPair(42, "Hello");

    // Accessing pair elements using member variables
    int intValueP = myPair.first;
    std::string stringValueP = myPair.second;

    std::cout << "Pair elements:\n";
    std::cout << "intValue: " << intValueP << "\n";
    std::cout << "stringValue: " << stringValueP << std::endl;

    // Modifying pair elements using member variables
    myPair.first = 100;
    myPair.second = "World";

    std::cout << "\nModified pair elements:\n";
    std::cout << "intValue: " << myPair.first << "\n";
    std::cout << "stringValue: " << myPair.second << std::endl;
    //----------------------------------------------------------------
    // Creating a tuple
    std::tuple<int, std::string, double> myTuple(42, "Hello", 3.14);

    // Accessing tuple elements using std::get
    int intValue = std::get<0>(myTuple);
    std::string stringValue = std::get<1>(myTuple);
    double doubleValue = std::get<2>(myTuple);

    std::cout << "Tuple elements:\n";
    std::cout << "intValue: " << intValue << "\n";
    std::cout << "stringValue: " << stringValue << "\n";
    std::cout << "doubleValue: " << doubleValue << "\n";

    // Modifying tuple elements using std::get and assignment
    std::get<0>(myTuple) = 100;
    std::get<1>(myTuple) = "World";
    std::get<2>(myTuple) = 2.71;

    std::cout << "\nModified tuple elements:\n";
    std::cout << "intValue: " << std::get<0>(myTuple) << "\n";
    std::cout << "stringValue: " << std::get<1>(myTuple) << "\n";
    std::cout << "doubleValue: " << std::get<2>(myTuple) << "\n";

    // Tuple size using std::tuple_size
    std::cout << "\nTuple size: " << std::tuple_size<decltype(myTuple)>::value << "\n";

    // Tuple element types using std::tuple_element
    using firstElementType = std::tuple_element<0, decltype(myTuple)>::type;
    using secondElementType = std::tuple_element<1, decltype(myTuple)>::type;
    using thirdElementType = std::tuple_element<2, decltype(myTuple)>::type;

    std::cout << "\nTuple element types:\n";
    std::cout << "First element type: " << typeid(firstElementType).name() << "\n";
    std::cout << "Second element type: " << typeid(secondElementType).name() << "\n";
    std::cout << "Third element type: " << typeid(thirdElementType).name() << "\n";
    //----------------------------------------------------------------
    print(1, 2.5, "Hello", 'A');  // Variadic template usage example
    //----------------------------------------------------------------
    // Using the default template argument for class A
    A<double> arr1(3.14);  // U defaults to int
    A<double, char> arr2(2.71, 'X');  // Explicitly provide char for U

    arr1.print();  // Output: T: 3.14, U: 0
    arr2.print();  // Output: T: 2.71, U: X

    // Using the constant template argument for MyArray
    MyArray<int, 5> myArr;  // Creates an array of size 5
    myArr.print();  // Output: 1 2 3 4 5
    // Using container2 with int
    container2<int> c3(10);
    
    // Auto deduction in C++17 (c3.add can take different types)
    c3.add(5.5);  // Adding a double to int, int will convert to double in operation
    
    // Printing the value after adding
    c3.print();

    // Testing the division templates
    std::cout << division(3, 2) << std::endl;       // Integer division
    std::cout << division(3.5, 2.2) << std::endl;   // Double division
    std::cout << division(3.5f, 2.2f) << std::endl; // Float division
    std::cout << division(3.5f, 2) << std::endl;    // Mixed float and int division

    // Using container with int
    container<int> c(15);
    c.print();

    // Using specialized container with double
    container<double> c_double(99.99);
    c_double.print();

    // Using the primary template (different types)
    array<int, double> a1(10, 20.5); // Output: Primary template
    
    // Using the partial specialization (same types)
    array<int, int> a2(10, 20);      // Output: Partial specialization
    // Create a shared_ptr p
    std::shared_ptr<int> x = std::make_shared<int>(10);
    // Create another shared_ptr p2, sharing ownership with p
    std::shared_ptr<int> x1 = x;
    std::cout << "p use_count() = " << x.use_count() << std::endl;
    x1.reset();
    std::cout << "p use_count() = " << x.use_count() << std::endl;
    x.reset();
    std::cout << "p use_count() = " << x.use_count() << std::endl;
    //----------------------------------------------------------------
    std::unique_ptr<Data> p = std::make_unique<Data>(2,3);
    std::unique_ptr<int> p2 = std::make_unique<int>(1);
    std::unique_ptr<int> p3 = std::make_unique<int>(2);
    fun(std::move(p2));
    std::cout<<p2.get()<<std::endl;
    auto fndeleter=[](int*p){
        std::cout<<"deleting p"<<std::endl;
        delete p;
    };
    std::unique_ptr<int, decltype(fndeleter)> p4(new int(3), fndeleter);
    // Using unique_ptr with a custom deleter to manage the FILE* resource
    std::unique_ptr<FILE, FileDeleter> file(fopen("example.txt", "w"));
    if (file) {
        std::cout << "File opened successfully\n";
        // Write to the file
        fprintf(file.get(), "Hello, world!\n");
    } else {
        std::cout << "Failed to open file\n";
    }
    //----------------------------------------------------------------
    namespace myc=mycontainer::myvector;
    using namespace mycontainer::myvector;
    //print();
    //----------------------------------------------------------------
    int *ptr =new(std::nothrow)int(5);
    if(ptr==nullptr){
        std::cerr<<"Memory allocation failed."<<std::endl;
        return 1;
    }
    delete ptr;
    //----------------------------------------------------------------

    /*
        try{
        throw MycustomException();
        }
        catch(const MycustomException& e){
            std::cerr<<e.what()<<std::endl;
        }
        fun2();
        return 0;
    */
    
}/*catch(...){
    std::cerr<<"An unknown exception occurred."<<std::endl;
    return 1;
}*/


