#include<bits/stdc++.h>

/*

class base{
    public:
    base(int a):a(a) {
        std::cout<<"Base constructor called with "<<a<<std::endl;
    }
    base (int a, int b):a(a){
        std::cout<<"Base constructor called with "<<a<<", "<<b<<std::endl;
    }
    virtual void print() const{
        std::cout<<"Base"<<std::endl;
    }
    virtual void print()   =0; //pure virtual function
    int a;
    
};
class derived:public base{
    public:
    void print(){
        std::cout<<"Derived"<<std::endl;
    } 
};
class Float:public base {
    public:
        void print() const { std::cout <<"Float"<<std::endl;}
};
class Int :public base {
    public:
        void print() const  { std::cout <<"Int"<<std::endl;}
        using base::base;
};
void fun(base* base){base->print();}
void fun(const base& base){base.print();}
*/
/*
//interface class
class base{
    public:
        virtual void print(){
            std::cout<<"Base"<<std::endl;
        } //pure
};
class drived:public base{
    public:
    void print()override{std::cout<<"print"<<std::endl;}
};
int main(){
    /*
        base d;
        derived x;
        d.print(); // Prints Base
        d.fun(); // Prints fun
        d.fun2(); // Private member function cannot be accessed
        dynamic binding is achieved by overriding
        virtual function and polymorphism is achieved by
        pointer to base class
        dynamic binding is based on
        runtime type identification (RTTI)
        base* b=&d;
        b->print(); // Prints derived
        dynamic binding is achieved by overriding
        virtual function and polymorphism is achieved by
        pointer to base class
        dynamic binding is based on
        runtime type identification (RTTI)
        concept polymorphism is based on
        reference to base class
        b=&x;
        b->print(); // Prints drives
//--------------------------------------------------------------    
    fun(new Int());
    fun(new Float());
    fun(Int());
    fun(Float());

    
    
    //Int obj(10);
    //Int obj(10,20);
    //1- it is not allowed to implemet instance from interface class
    //base d;
    //2-in the inheritance class we must implement all the pure virtual methods
    drived d;
    d.print(); // Prints print
  
    return 0;
}

*/
/*
// Abstract class with pure virtual functions
class BaseAbstract {
public:
    // Virtual functions to be overridden by derived classes
    virtual void print() = 0;  // Pure virtual function
    virtual void print2() = 0; // Pure virtual function
    virtual void print3() = 0; // Pure virtual function
};

// Derived class implementing BaseAbstract
class Data : public BaseAbstract {
public:
    // Override and define the virtual functions
    void print() override {
        std::cout << "Data class: print()" << std::endl;
    }

    void print2() override {
        std::cout << "Data class: print2()" << std::endl;
    }

    void print3() override {
        std::cout << "Data class: print3()" << std::endl;
    }
};

// Derived class from Base with specific implementation
class Derived : public BaseAbstract {
public:
    // Implement the required virtual functions from the base class
    void print() override {
        std::cout << "Derived class: print()" << std::endl;
    }

    void print2() override {
        std::cout << "Derived class: print2()" << std::endl;
    }

    void print3() override {
        std::cout << "Derived class: print3()" << std::endl;
    }
};

int main() {
    Data d2;
    Derived d1;

    std::cout << "Calling functions from Data object: " << std::endl;
    d2.print();
    d2.print2();
    d2.print3();

    std::cout << "\nCalling functions from Derived object: " << std::endl;
    d1.print();
    d1.print2();
    d1.print3();

    return 0;
}

*/
/*
class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }

    void dogSpecific() {
        std::cout << "Dog specific function." << std::endl;
    }
};

void fun(Animal *animal) {
    // Call the makeSound function of the Animal pointer (can be overridden in derived classes)
    animal->makeSound();

    // Try dynamic casting to check if the object is of type Dog
    Dog *dog = dynamic_cast<Dog *>(animal);
    if (dog != nullptr) {
        // If cast is successful, call Dog-specific function
        dog->dogSpecific();
    } else {
        std::cout << "The object is not a Dog." << std::endl;
    }
}

int main() {
    // Create a Dog object but treat it as an Animal pointer
    Animal *animal1 = new Dog();

    // Pass the Animal pointer to the function
    fun(animal1);

    // Clean up
    delete animal1;

    return 0;
}
*/
/*
void construct_test() {
    // Default constructor
    std::string s = "Hello, World!";
    // Copy constructor
    std::string str(s);
    // Move constructor
    std::string str2(std::move(str)); // str is now in a valid but unspecified state
    //Fill constructor
    std::string str3(10, 'A'); // Creates a string with 10 'A's
    // Range constructor
    std::string str4(s.begin(), s.end()); // Copies from s
    // Substring constructor
    std::string str5(s, 0, 5); // Copies first 5 characters of s
    // Initializer list constructor
    std::vector<char> v{'H', 'e', 'l', 'l', 'o'};
    std::string str6(v.begin(), v.end()); // Creates string from vector
    // Initializer list constructor (using a list of characters)
    std::string str7{'H', 'i'}; // Creates a string from an initializer list

    // Output the constructed strings
    std::cout << "String from default: " << s << std::endl;
    std::cout << "String from copy: " << str2 << std::endl;
    std::cout << "String from fill: " << str3 << std::endl;
    std::cout << "String from range: " << str4 << std::endl;
    std::cout << "String from substring: " << str5 << std::endl;
    std::cout << "String from vector: " << str6 << std::endl;
    std::cout << "String from initializer list: " << str7 << std::endl;
}
void string_functions() {
    std::string s = "Hello, World!";

    // Display the size of the string
    std::cout << "Size: " << s.size() << std::endl;         // Number of characters in the string
    std::cout << "Length: " << s.length() << std::endl;     // Same as size
    std::cout << "Capacity: " << s.capacity() << std::endl; // Allocated memory for the string
    std::cout << "Max size: " << s.max_size() << std::endl; // Maximum possible size of the string

    // Uncommenting the following line will clear the string
    // s.clear(); // The string will be empty after this

    // Find the substring "World"
    auto it = s.find("World");

    if (it == std::string::npos) {
        std::cout << "'World' not found" << std::endl; // Substring not found
    } else {
        std::cout << "'World' found at index: " << it << std::endl; // Index of the found substring
    }

    // Output a substring from index 0 to 5
    std::cout << "Substring (0, 5): " << s.substr(0, 5) << std::endl; // Outputs "Hello"
}
class MyData {
public:
    int x;
    int y;
    // Constructor
    MyData(int x, int y) : x(x), y(y) {
        std::cout << "MyData constructor" << std::endl;
    }
    // Initializer list constructor
    MyData(std::initializer_list<int> v) {
        std::cout << "MyData initializer list constructor" << std::endl;
        for (auto i : v) {
            std::cout << i << std::endl;
        }
    }
};


// Function to check if 'body' starts with the 'prefix'
bool starts_with(const std::string& body, const std::string& prefix) {
    return body.find(prefix) == 0;  // Check if 'prefix' is found at the beginning of 'body'
}

// Alternative implementation using substr
bool starts_with2(const std::string& body, const std::string& prefix) {
    if (body.length() < prefix.length()) {
        return false;  // 'body' is shorter than 'prefix', cannot start with it
    }
    return body.substr(0, prefix.length()) == prefix;  // Compare the substring with 'prefix'
}
int main() {
    construct_test();
    string_functions();
     std::cout << std::boolalpha;  // Print boolean values as true/false

    // Test the starts_with function
    std::cout << "starts_with(\"Hello world\", \"Hello\"): " 
              << starts_with("Hello world", "Hello") << std::endl;

    // Test the starts_with2 function
    std::cout << "starts_with2(\"Hello world\", \"Hello\"): " 
              << starts_with2("Hello world", "Hello") << std::endl;
    // Example usage of MyData class
    MyData data1(1, 2); // Calls the regular constructor
    MyData data2{3, 4}; // Calls the initializer list constructor

    return 0;
}

*/
