/*#include<iostream>
class myData{
    public:
        myData(){
            std::cout<<"default constructor"<<std::endl;
        }
        myData(int a){
            std::cout<<"parameterized constructor1"<<std::endl;
            this->x = a;
        }
        myData(int a, int b):myData(a){
            std::cout<<"parameterized constructor2"<<std::endl;
            this->y = b;
        }
        //myData(int x, int y){
        //    std::cout<<"parameterized constructor"<<std::endl;
        //    this->x = x;
        //    this->y = y;
        //}
    private:
        int x;
        int y;
};
int main(){
    myData obj1; // calls parameterized constructor
    myData obj2(5,10); // calls parameterized constructor
    return 0;
}*/
/*#include <iostream>
class myData {
public:
    bool a;
    myData() : a(true) {}
    // Parameterized constructor
    myData(bool a) : a(a) {}
    // Delegating constructor
    myData(int value) : myData(static_cast<bool>(value)) {}
    void display() {
        std::cout << "Value of a: " << a << std::endl;
    }
};

int main() {
    myData m1;
    m1.display();
    myData m2(false);
    m2.display();
    myData m3(1);
    m3.display();

    return 0;
}*/
/*#include <iostream>
class Data {
public:
    bool flag = 1;
    int value = 0;
    // Default constructor
    Data() {
        std::cout << "Default" << std::endl;
    }
    // Constructor with one parameter
    Data(bool flag) : Data() {
        this->flag = flag;
        std::cout << "1 Param" << std::endl;
    }
    // Constructor with two parameters
    Data(bool flag, int value) : Data(flag) {
        this->value = value;
        std::cout << "2 Param" << std::endl;
    }
    // Print function to display data
    void PrintInt() {
        std::cout << "Flag: " << flag << ", Value: " << value << std::endl;
    }
};

int main() {
    Data d1;               // Calls default constructor
    Data d2(true);         // Calls constructor with one parameter
    Data d3(true, 10);     // Calls constructor with two parameters
    // Print values
    d1.PrintInt();
    d2.PrintInt();
    d3.PrintInt();

    return 0;
}*/
/*#include <iostream>
class myData {
public:
  // Constructor with initializer list
  // Ensure 'number' is initialized after 'a', since it references 'a'
    myData(int a, int b) : a(a), b(b), ptr(&this->a), number(this->a) {}
  // Const getter - cannot modify class members, but can modify local variables
  // and arguments
  int getter(int temp) const {
    // 1- You cannot modify any member variables (a and b) inside a const member
    // function a++; // Error, 'a' is const in this context

    // 2- You can create local variables and modify them
    int myvalue = 10;
    myvalue++; // This is allowed

    // 3- You can modify the function argument (since it is passed by value)
    temp++; // This is allowed

    // 4- You can modify static members
    classmember++;
    number = 100;
    return a; // Returning the value of 'a'
  }
  // A const member function cannot modify member variables unless they are
  // mutable
  void fun() const {
    // Cannot modify 'a' or 'b'
    // a++; // Error
  }
  // Non-const member function
  void test() { a++; }

  // Non-const getter
  int getter(int temp) {
    temp++;
    return a;
  }
  // Const member function that returns a pointer
  int *getPtr() const { return ptr; }
  // ISSUE: Returning a non-const reference from a const member function
  // This is problematic because the reference can be used to modify the object
  int &getNumber() const {
    return number; // This is problematic and breaks const-correctness
  }

private:
  int a;
  int b;
  int &number;            // Reference to 'a', must be initialized after 'a'
  int *ptr;               // Pointer to 'a'
  static int classmember; // Static member variable shared across all instances
};

// Definition of the static member variable
int myData::classmember = 0;

int main() {
  // 6- A const instance can only call const member functions
  const myData data1(1, 2);


  // The following would cause an error, because 'fun()' is not a const function
  // data1.fun(); // Uncommenting this line will cause a compilation error

  // A non-const instance can call both const and non-const member functions
  myData data2(3, 4);
  std::cout << "Non-const instance calling getter: " << data2.getter(5)
            << std::endl;

  data2.getter(3);
  // data2.fun(); // Error: 'fun()' is not a const function
  // data2.test();
  data2.getter(4);
  data2.getNumber() = 10;
  std::cout << "Modified number: " << data2.getNumber() << std::endl;


  return 0;
}*/
/*#include<iostream>
class temp; //forwards declaration
void fun(); //forwards declaration
class myData{
    public:
       myData(int i, int j):i(i), j(j) {}
    private:
    friend class temp;
    friend void fun(){
        myData data(1,2);
        std::cout<<data.i<<std::endl<<data.j<<std::endl;
    }
        int i, j;
    friend std::ostream& operator<<(std::ostream&os,const myData &data){
        os<<data.i<<" "<<data.j<<std::endl;
        return os;
    }
};
class temp{
    public:
    temp(){
        myData data(3,4);
        std::cout<<data.i<<std::endl<<data.j<<std::endl;
    }
};
int main(){
    myData data(1,2);
    fun();
    std::cout<<data<<std::endl;
    return 0;
}*/
/*#include <iostream>

class myData {
    public:
        myData() { counter++;}
        void print() const {std::cout << "Counter: " << counter << std::endl;}
        static int counter; // Static member declaration
        static const int MAX; // Static const member declaration
        static const int MIN; // Static const member declaration
        static const float min; // Static const member declaration
    private:
        // Static members need to be defined outside the class
    };
// Static member initialization
const float myData::min = 0.0f; // Initialization of static const member declaration
int myData::counter = 0; // Initialization of static member
const int myData::MAX = 100; // Initialization of static const member
const int myData::MIN = 0;   // Initialization of static const member
int main() {
    myData d1;
    myData d2;
    myData d3;
    myData d4;
    myData d5;
    // Accessing static member via the class name
    std::cout << "Counter: " << myData::counter << std::endl;
    // Alternatively, accessing via an object (not recommended but valid)
    d1.print();
    return 0;
}*/
/*#include<iostream>
class myData{
    public:
        myData(){}
        static const int temp;
};const int myData::temp = 10;
void getData(const int &a){}
int main(){
    myData data;
    getData(data.temp);
    std::cout<<data.temp<<std::endl;
    return 0;
}*/ 
/*#include <iostream>
class myData{
    public:
        myData(){}
        static void myfun(){//1-static function in not related to instance 
                                    //it is related to class     
            std::cout<<"Static member function"<<std::endl;
            //temo =10; //2-Error cannot access to (this)
            number = 20;//3-ok
        }
        int temp;
        static int number;
};
int myData::number = 10;
int main(){
    myData::myfun();//4-calling from class name and from instance name
    myData data1, data2;
    
    return 0;
}*/
/*#include <bits/stdc++.h>
int main() {
    // Data extraction
    std::string frame = "Ebrahim 1147329418 700.50";
    std::string name;
    long id;
    double amount;
    std::stringstream ss(frame);
    ss >> name >> id >> amount;
    std::cout << "Name: " << name << "\nID: " << id << "\nAmount: " << amount << std::endl;
    // Regex exampl
    std::string info = "myNumber is 01147329418 , myEmail is ibrahimmostafa9939@gmail.com";
    // Regex for phone number (11 digits)
    std::regex phonePattern("\\d{11}");
    std::smatch phoneMatch;
    if (std::regex_search(info, phoneMatch, phonePattern)) {
        std::cout << "Phone Number: " << phoneMatch.str() << std::endl;
    } else {
        std::cout << "No phone number found." << std::endl;
    }
    // Regex for email
    std::regex emailPattern("\\b\\w+@\\w+\\.\\w+\\b");
    std::smatch emailMatch;
    if (std::regex_search(info, emailMatch, emailPattern)) {
        std::cout << "Email: " << emailMatch.str() << std::endl;
    } else {
        std::cout << "No email found." << std::endl;
    }

    return 0;
}*/










