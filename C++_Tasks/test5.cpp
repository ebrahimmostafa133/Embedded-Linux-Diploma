#include<bits/stdc++.h>
#include<string.h>

class LCD{
    public:
    std::string msg;
    int cursor = 0;
    void display(){
        std::cout<<msg<<std::endl;
    }
    LCD &operator +=(const std::string &message){
        this->msg = message;
        return *this;
    }
    bool operator <(const LCD &l){
        return this->msg.size() < l.msg.size();
    }
    void operator++(){this->cursor++;}
    int operator++(int){
        int temp = this->cursor;
        this->cursor++;
        return temp;
    }
};
//-----------------------------------------------------------------------------

class Data {
    std::string msg;  // Correct std::string
    int courser = 0;  // Initialize courser to 0
    public:
    Data()=default; 
    Data(std::string msg, int courser): msg(msg), courser( courser ){
        //alocate mem
        //std::cout<<" "<<std::endl;
        std::cout<<"constructor called"<<std::endl;
    }
    explicit Data(std::string msg):msg(msg){}
    friend std::ostream &operator<<(std::ostream &os, const Data &dt);
    void operator()(std::string msg,int cursor){
        std::cout<<"Benzema"<<std::endl;
        std::cout<<"the old values were "<<*this<<std::endl;
        this->msg = msg;
        this->courser = cursor;
        std::cout<<"the new values are "<<*this<<std::endl;
    }
    // Overload operator== to compare two Data objects
    bool operator==(const Data& d) const {
        return (this->msg == d.msg) && (this->courser == d.courser);
    }
};

//-----------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Data &dt){
    os<<dt.msg<<" "<<std::endl;
    return os;
}
//-----------------------------------------------------------------------------
class Complex {
    int real;
    float img;
    public:
        // Default constructor
        Complex() = default;
        // Parameterized constructor
        Complex(int real, float img) : real(real), img(img) {}
        // Overload operator+ for adding an integer to the real part
        int operator+(int num) {
            std::cout << "real" << std::endl;
            return this->real + num;
        }
        // Overload operator+ for adding a float to the imaginary part
        float operator+(float img) {
            std::cout << "img" << std::endl;
            return this->img + img;
        }
        // Overload operator+ for adding two Complex objects
        Complex operator+(const Complex& temp) {
            std::cout << "Complex" << std::endl;
            Complex result;
            result.img = this->img + temp.img;
            result.real = this->real + temp.real;
            return result;
        }
        // Function to print the complex number
        void print() const {
            std::cout << "Complex number: " << real << " + " << img << "i" << std::endl;
        }
        void operator()(void) const {
        std::cout << "Real is: " << real << std::endl;
        std::cout << "Img is: " << img << std::endl;
        }
        // Function accepting std::function
        void fun(std::function<void(void)> f) {
            f(); // Call the function object
        }
};
//-----------------------------------------------------------------------------
std::string operator+(const LCD &l,const std::string &message){
    return l.msg + message;
    }
    //custom user defined literals
void operator""_print(const char *msg,size_t len){
        std::cout<<msg<<std::endl;
    }
//-----------------------------------------------------------------------------
template<typename T>struct is_integral :public std::false_type{};
template<>struct is_integral<int>:std::true_type{};
template<typename T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
is_integral_v2(){
    return true;
}
//-----------------------------------------------------------------------------
int main(){
    is_integral_v2<int>();
    "Hallo Benzema"_print;
    LCD lcd{"hello world!"};
    LCD lcd1{"hello "};
    std::string mssage ="From Egyptians";
    std::string result =lcd+mssage;
    lcd.display();
    std::cout<<result<<std::endl;
    if(lcd<lcd1)
        std::cout<<"lcd is smaller than lcd1"<<std::endl;
    else
        std::cout<<"lcd is not smaller than lcd1"<<std::endl;
    ++lcd1;
    int c=lcd++;
    int y=10;
    int l=y++;
    Data d1{"World", 0};
    Data d2{"Egypt", 0};
    // Compare the two objects
    if (d1 == d2) {
        std::cout << "Equal\n";
    } else {
        std::cout << "Not Equal\n";
    }
    Complex A(1, 1.5f);  
    Complex B(2, 2.5f);  
    Complex C;           

    int reals = A + 12;     
    float imgs = A + 1.5f;   
    C = A + B;    

    C.print();
    std::cout << "Real part after addition: " << reals << std::endl;
    std::cout << "Imaginary part after addition: " << imgs << std::endl;
    
    B();
    std::function<void(void)>f=Complex();
    f();

    std::vector<Data>v{Data("ezayk ya m3lm", 0), Data("hemahema",2)};
    Data d3{"BenzemaBenzema",0};
    std::function<void(std::string,int)>f2=d1;
    f2("brhoma",2);
    

    Data benzema=Data(std::string("ezayk ya m3lm"));
    return 0;
}







