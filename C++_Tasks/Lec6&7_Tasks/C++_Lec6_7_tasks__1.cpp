//---------  lec 6,7 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>

//---------------------- Task1 ----------------------
// Create Class behave like string/Integer totally

#include <iostream>
#include <string>

class DualType {
private:
    std::string strValue;
    int intValue;
    bool isString;

public:
    // Constructors
    DualType() : strValue(""), intValue(0), isString(false) {} // Default constructor

    DualType(const std::string& s) : strValue(s), intValue(0), isString(true) {} // Construct from string

    DualType(int i) : strValue(""), intValue(i), isString(false) {} // Construct from integer

    // Assignment operator for string
    DualType& operator=(const std::string& s) {
        strValue = s;
        intValue = 0;
        isString = true;
        return *this;
    }

    // Assignment operator for integer
    DualType& operator=(int i) {
        intValue = i;
        strValue = "";
        isString = false;
        return *this;
    }

    // Operator overload for addition with integer
    DualType operator+(int i) const {
        if (isString) throw std::invalid_argument("Cannot add integer to string.");
        return DualType(intValue + i);
    }

    // Operator overload for substraction with integer
    DualType operator-(int i) const {
        if (isString) throw std::invalid_argument("Cannot add integer to string.");
        return DualType(intValue - i);
    }

    // Operator overload for multiplication with integer
    DualType operator*(int i) const {
        if (isString) throw std::invalid_argument("Cannot add integer to string.");
        return DualType(intValue * i);
    }

    // Operator overload for division with integer
    DualType operator/(int i) const {
        if (isString) throw std::invalid_argument("Cannot add integer to string.");
        if (i == 0) throw std::invalid_argument("Cannot divide by zero.");
        return DualType(intValue / i);
    }

    // Operator overload for addition with string
    DualType operator+(const std::string& s) const {
        if (!isString) throw std::invalid_argument("Cannot add string to integer.");
        return DualType(strValue + s);
    }
    // Operator overload for substraction with string
    DualType operator-(const std::string& s) const {
        if (!isString) throw std::invalid_argument("Cannot add string to integer.");
        return DualType(strValue.substr(0, strValue.size() - s.size()));
    }


    // Overloading operator<< for output
    friend std::ostream& operator<<(std::ostream& os, const DualType& dt) {
        if (dt.isString) {
            os << dt.strValue;
        } else {
            os << dt.intValue;
        }
        return os;
    }

    // Conversion to integer
    operator int() const {
        if (isString) throw std::invalid_argument("Cannot convert string to int.");
        return intValue;
    }

    // Conversion to string
    operator std::string() const {
        if (!isString) throw std::invalid_argument("Cannot convert int to string.");
        return strValue;
    }

    // Equality check for string
    bool operator==(const std::string& s) const {
        return isString && strValue == s;
    }

    // Equality check for integer
    bool operator==(int i) const {
        return !isString && intValue == i;
    }

    // Function to check type
    bool isStringType() const { return isString; }
};

int main() {
    // Integer example
    DualType num(42);
    std::cout << "Integer: " << num << std::endl;

    // String example
    DualType text("Hello");
    std::cout << "String: " << text << std::endl;

    // Performing operations
    num = num + 8;
    std::cout << "After adding 8: " << num << std::endl;

    num = num - 8;
    std::cout << "After subtracting 8: " << num << std::endl;

    num = num * 2;
    std::cout << "After multiplying by 2: " << num << std::endl;

    num = num / 2;
    std::cout << "After dividing by 2: " << num << std::endl;

    text = text + std::string(" World!");
    std::cout << "After adding string: " << text << std::endl;

    text = text -std::string("ld!");
    std::cout << "After removing 'ld!': " << text << std::endl;

    // Equality check for string
    std::cout << (text == "Hello World") << std::endl;

    // Checking for types and conversion
    if (text.isStringType()) {
        std::string extractedStr = text;
        std::cout << "Extracted string: " << extractedStr << std::endl;
    }

    if (!num.isStringType()) {
        int extractedInt = num;
        std::cout << "Extracted integer: " << extractedInt << std::endl;
    }

    return 0;
}
