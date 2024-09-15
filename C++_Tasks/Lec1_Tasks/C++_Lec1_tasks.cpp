//---------  lec 1 ----------
// author: Ebrahim Mostafa

#include <bitset>  // for std::bitset
#include <cmath>   // for std::sqrt and std::pow
#include <iomanip> // for std::setw
#include <iostream>
#include <string> // for std::string manipulation

// Function to create and display a table for ASCII codes
void displayASCIITable() {
  std::cout << "Char | ASCII" << std::endl;
  std::cout << "--------------" << std::endl;
  for (int i = 32; i <= 126; ++i) { // Display printable ASCII characters
    std::cout << "  " << char(i) << "  |  " << i << std::endl;
  }
  std::cout << std::endl;
}

// Function to find the maximum number between three values
int findMaximum(int a, int b, int c) { return std::max(a, std::max(b, c)); }

// Function to check if three sides form a right-angle triangle
bool isRightAngleTriangle(int a, int b, int c) {
  int x = std::max(a, std::max(b, c)); // hypotenuse
  int y, z;

  if (x == a) {
    y = b;
    z = c;
  } else if (x == b) {
    y = a;
    z = c;
  } else {
    y = a;
    z = b;
  }

  return x * x == y * y + z * z;
}

// Function to determine if a letter is a vowel or not
bool isVowel(char ch) {
  ch = std::tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Function to display a multiplication table for a given number
void displayMultiplicationTable(int num) {
  std::cout << "Multiplication Table for " << num << ":" << std::endl;
  for (int i = 1; i <= 10; ++i) {
    std::cout << num << " * " << i << " = " << num * i << std::endl;
  }
  std::cout << std::endl;
}

// Function to calculate the sum of the digits of an integer
int sumOfDigits(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

// Function to convert a decimal number to binary and vice versa
void decimalToBinaryAndViceVersa() {
  int decimal;
  std::cout << "Enter a decimal number: ";
  std::cin >> decimal;
  std::cout << "Binary representation: " << std::bitset<16>(decimal)
            << std::endl;

  std::string binary;
  std::cout << "Enter a binary number: ";
  std::cin >> binary;
  std::cout << "Decimal representation: " << std::stoi(binary, nullptr, 2)
            << std::endl;
}

int main() {
  // Task 1: Create a table for ASCII code
  displayASCIITable();

  // Task 2: Find the maximum number between three values
  int a, b, c;
  std::cout << "Enter three integers: ";
  std::cin >> a >> b >> c;
  std::cout << "The maximum value is: " << findMaximum(a, b, c) << std::endl;

  // Task 3: Check if the given sides form a right-angle triangle
  int x, y, z;
  std::cout << "Enter three sides of a triangle: ";
  std::cin >> x >> y >> z;
  if (isRightAngleTriangle(x, y, z)) {
    std::cout << "The sides form a right-angle triangle." << std::endl;
  } else {
    std::cout << "The sides do not form a right-angle triangle." << std::endl;
  }

  // Task 4: Decide if a letter is a vowel or not
  char ch;
  std::cout << "Enter a letter: ";
  std::cin >> ch;
  if (isVowel(ch)) {
    std::cout << ch << " is a vowel." << std::endl;
  } else {
    std::cout << ch << " is not a vowel." << std::endl;
  }

  // Task 5: Generate a multiplication table
  int num;
  std::cout << "Enter a number to display its multiplication table: ";
  std::cin >> num;
  displayMultiplicationTable(num);

  // Task 6: Summation of the digits of an integer entered by the user
  int number;
  std::cout << "Enter an integer: ";
  std::cin >> number;
  std::cout << "Sum of the digits: " << sumOfDigits(number) << std::endl;

  // Task 7: Change from decimal to binary and vice versa
  decimalToBinaryAndViceVersa();

  return 0;
}
