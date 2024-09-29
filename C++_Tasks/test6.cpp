#include<bits/stdc++.h>
/*class String{
    private:
        char* str;
        int size;
    public:
        // Constructor
        String (char *str):str(str){}
        String(const String &obj){
            size = strlen(obj.str)+1;
            str = new char[size];
            strcpy(str, obj.str);
        }
        void fun(){std::cout<<str<<std::endl;}
        void setchar(char value){*str=value;}
};
String get_instance(){
    static  char arrat[] = "halloc ";
    String t1{arrat};
    return t1;
}

int main(){
    char array[]="HALLO";
    String t1{array};

    String t2(get_instance());
    t1.setchar('a');
    t1.fun();
    t2.fun();
    return 0;
}
*/
/*class String{
    private:
    public:
        String() {std::cout << "Default constructor" << std::endl;}
        ~String() {std::cout << "Destructor" << std::endl;}
        String(const String &obj) {std::cout << "Copy constructor" << std::endl; }    
};
String getInstance() {
        String t1; // Temporary local object
        return t1; // This will invoke the copy constructor
    }
int main() {
    String t1 (getInstance());
    return 0;
}*/
/*class String {
    private:
        int* ptr; // Pointer to an integer value
    public:
        // Constructor that initializes the pointer
        String(int value) {
            this->ptr = new int(value);
            std::cout << "Constructor called, value = " << *ptr << std::endl;
        }
        // Destructor to free memory
        ~String() {
            delete ptr;
            ptr = nullptr; // Avoid dangling pointer
            std::cout << "Destructor called for " << this << std::endl;
        }
        // Copy constructor for deep copy
        String(const String& obj) {
            ptr = new int(*obj.ptr); // Deep copy of the pointer
            std::cout << "Copy constructor called" << std::endl;
        }
        // Assignment operator overload for deep copy
        String& operator=(const String& obj) {
            std::cout << "Assignment operator called" << std::endl;
            if (this != &obj) { // Avoid self-assignment
                if (this->ptr) {
                    delete this->ptr; // Clean existing data
                }
                this->ptr = new int(*obj.ptr); // Deep copy of the object
            }

            return *this; // Return the current object
        }
        int getValue() const {
            return *ptr;
        }
};

int main() {
    String s1(10);        // Calls constructor
    String s3(20);        // Calls constructor   
    String s2 = s1;       // Calls copy constructor
    s3 = s1;              // Calls assignment operator
    std::cout << "s1 value: " << s1.getValue() << std::endl;
    std::cout << "s2 value: " << s2.getValue() << std::endl;
    std::cout << "s3 value: " << s3.getValue() << std::endl;
    return 0;
}*/
/*class String {
private:
    char *m_Buffer = nullptr;
    unsigned int m_Size;
public:
    // Constructor that takes a C-string
    String(const char *string) {
        std::cout << "String(const char *string)" <<string << std::endl;
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0; // Null-terminate the string
    }
    // Copy constructor for deep copy
    String(const String &other) : m_Size(other.m_Size) {
        std::cout << "String(const String &other)" <<other.m_Buffer << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }
    // Assignment operator for deep copy
    String &operator=(const String &other) {
        std::cout << __PRETTY_FUNCTION__ <<other.m_Buffer<< std::endl;
        if (this == &other)
            return *this; // Return *this to deal with self-assignment
        delete[] m_Buffer; // Clean up the old buffer
        m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        return *this;
    }
    // Destructor
    ~String() {
        delete[] m_Buffer;
    }
};
int main() {
    String name = "moatasem"; // Implicit constructor call
    String name2 = name;      // Copy constructor call
    name2 = "Zein moatasem";  // Implicit constructor + assignment operator call

    return 0;
}*/
/*int &fun(){
    static int a=5;
    return a;
}
int fun2(){
    static int a=5;
    return a;
}
int main(){
    fun()/*Lvalue =10/*Rvalue;
    int x/*Lvalue=fun()/*Rvalue;//What is the fun return ?Lvalue
    std::cout<<fun()<<std::endl;
    //fun2()/*Rvalue =10;
    int y=fun2();
    std::cout<<y<<std::endl;
    return 0;
}*/
/*int main(){
    std::string name = "moatasem";
    std::string name2 = std::move(name);

    std::cout<<name2 << std::endl;
    std::cout<<name << std::endl;
    return 0;
}*/
int main() {
    int y = 10;    // 'y' is an Lvalue (it has a name and an address)
    int &x = y;    // 'x' is an Lvalue reference to 'y'

    // x is an Lvalue because it has a name and an address
    // The value category of 'x' is Lvalue
    // The type category of 'x' is Lvalue reference (int&)

    // int &temp = 10; // ERROR: Lvalue reference must be initialized with an Lvalue, but '10' is an Rvalue

    // Rvalue reference declaration
    int &&rvalueref = 10;

    // The value category of 'rvalueref' is Lvalue (because rvalueref has a name)
    // The type category of 'rvalueref' is an Rvalue reference (int&&)
    
    // Printing the address of the rvalue reference
    std::cout << "The address of rvalue ref is: " << &rvalueref << std::endl;

    // int &r = 10; // ERROR: Lvalue reference cannot bind to an Rvalue (like a literal '10')
    
    // Rvalue references are designed to bind to temporaries or moved objects (sole ownership)
    int &&rvalueref2 = std::move(y); // 'y' is an Lvalue, but std::move turns it into an Rvalue

    // 'rvalueref2' is now a reference to the value of 'y' (which is 10), but y is now in a "moved-from" state.
    std::cout << "The value of y after std::move: " << y << std::endl; // Note: This might still print '10' but 'y' is in an unspecified state after std::move.

    // WRONG EXPLANATION (trivial data type)
    // Explanation correction: 'std::move' doesn't "move" the object, it just casts 'y' to an Rvalue reference
    // allowing it to be "moved" (i.e., passed to a function or assigned) without copying.

    // GOOD QUESTION:
    // Here is an example involving a pointer.
    int moatasem = 10;       // 'moatasem' is an Lvalue (has a name and address)
    int *ptr = &moatasem;    // 'ptr' is a pointer to the Lvalue 'moatasem'
    
    *ptr = 100;              // Dereferencing the pointer 'ptr' and assigning '100' to the location of 'moatasem'
    std::cout << "Value of moatasem: " << moatasem << std::endl; // Prints '100', as moatasem is now updated to 100

    // Lvalues (like 'moatasem') have both a name and an address.
    // Rvalues (like temporary objects or literals) have no name but can have an address if bound to an Rvalue reference.
    
    return 0;
}
