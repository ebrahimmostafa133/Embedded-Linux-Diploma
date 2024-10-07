#include <bits/stdc++.h>

class String {
private:
    char* str;
    size_t size;

public:
    // Copy Constructor
    String(const String& obj) {
        std::cout << "Copy Constructor " << this << std::endl;
        size = obj.size;
        str = new char[size + 1]; // Allocating memory in the heap
        std::strcpy(str, obj.str); // Copying the content of obj.str to str
    }

    // Move Constructor
    String(String&& obj) {
        std::cout << "Move Constructor " << this << std::endl;
        size = obj.size;
        str = obj.str; // Take ownership of obj's data
        obj.str = nullptr; // Reset obj's pointer to avoid double delete
        obj.size = 0;      // Reset size
    }

    // Move Assignment Operator
    String& operator=(String&& obj)  {
        std::cout << "Move Assignment " << this << std::endl;
        if (this != &obj) { // Self-assignment check
            delete[] str; // Release current resources
            // Steal resources from obj
            str = obj.str;
            size = obj.size;
            // Nullify the source object
            obj.str = nullptr;
            obj.size = 0;
        }
        return *this;
    }

    // Copy Assignment Operator
    String& operator=(const String& obj) {
        std::cout << "Copy Assignment " << this << std::endl;
        if (this != &obj) { // Self-assignment check
            delete[] str; // Release current resources
            // Allocate new memory and copy the data
            size = obj.size;
            str = new char[size + 1];
            std::strcpy(str, obj.str);
        }
        return *this;
    }

    // Destructor
    ~String() {
        std::cout << "Destructor " << this << std::endl;
        delete[] str;
    }

    // Constructor from C-style string
    explicit String(const char* s) {
        std::cout << "Constructor " << this << std::endl;
        size = std::strlen(s);
        str = new char[size + 1];
        std::strcpy(str, s);
    }

    // Display function for testing
    void display() const {
        if (str) {
            std::cout << "String: " << str << " Size: " << size << std::endl;
        } else {
            std::cout << "String is empty." << std::endl;
        }
    }
};

class MyData {
public:
    // Constructor accepting a string
    MyData(std::string name) : name(name) {
        std::cout << "Constructor " << this << std::endl;
    }
    //rule of zero
    MyData(const MyData& obj) = default;            // Copy constructor (defaulted)
    MyData(MyData&& obj) = default;                 // Move constructor (defaulted)
    MyData& operator=(const MyData& obj) = default; // Copy assignment operator (defaulted)
    MyData& operator=(MyData&& obj) = default;      // Move assignment operator (defaulted)
    virtual ~MyData() = default;                    // Virtual destructor (defaulted)
private:
    std::string name; // Private member variable
};

class base{
    std::string name;
    public:
    base(std::string n):name(n){
        std::cout<<"Base constructor"<<this<<std::endl;
    }
    base(){
        std::cout<<"Base default constructor "<<this<<std::endl;
    }
    void print(){
        std::cout<<"print"<<std::endl;
    }
    ~base(){
        std::cout<<"Base destructor"<<this<<std::endl;
    }
};
class base1{
    std::string name;
    public:
    base1(std::string n):name(n){
        std::cout<<"Base1 constructor"<<this<<std::endl;
    }
    base1(){
        std::cout<<"Base1 default constructor "<<this<<std::endl;
    }
    void print(){
        std::cout<<"print1"<<std::endl;
    }
    ~base1(){
        std::cout<<"Base1 destructor"<<this<<std::endl;
    }
};
class derived:public base,public base1{
    std::string name;
    public:
    derived(std::string n):base(n),name(n){
        std::cout<<"Derived constructor"<<this<<std::endl;
    }
    derived(){
        std::cout<<"Derived default constructor "<<this<<std::endl;
    }
    ~derived(){
        std::cout<<"Derived destructor"<<this<<std::endl;
    }
};

// Base class
class ClassA {
public:
    int a;
    ClassA() : a(0) {}  // Constructor to initialize a
};
// Derived class B inheriting from ClassA
class ClassB : virtual public ClassA {
public:
    int b;
    ClassB() : b(0) {}  // Constructor to initialize b
};
// Derived class C inheriting from ClassA
class ClassC : virtual public ClassA {
public:
    int c;
    ClassC() : c(0) {}  // Constructor to initialize c
};
// Derived class D inheriting from ClassB and ClassC
class ClassD : public ClassB, public ClassC {
public:
    int d;
    ClassD() : d(0) {}  // Constructor to initialize d
};

int main() {
    derived d;
    d.base1::print();

     // Create an object of ClassD
    ClassD obj;

    // Accessing members from different classes
    obj.a = 100;  // ClassA's member (inherited by ClassB and ClassC)
    obj.b = 200;  // ClassB's member
    obj.c = 300;  // ClassC's member
    obj.d = 400;  // ClassD's member

    // Output values
    std::cout << "a = " << obj.a << std::endl;
    std::cout << "b = " << obj.b << std::endl;
    std::cout << "c = " << obj.c << std::endl;
    std::cout << "d = " << obj.d << std::endl;
    return 0;
}
