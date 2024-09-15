//---------  lec 4,5 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>

//----------------------------------------------------------------
int &f() {
  static int x = 10; // Static variable
  std::cout << x << std::endl;
  return x;
}
//----------------------------------------------------------------

int main() {
    //----------------------------------------------------------------
    // Call function and use its returned reference
    f() = 20; // Assign 20 to the static variable x via the function f()
    std::cout << "Updated value: " << f()
            << std::endl; // Print updated value of x
    //----------------------------------------------------------------

    // fill array from 10 to 10000 sequentially
    int start = 10;
    int end = 10000;
    int size = end - start + 1;
    // Create a vector of the appropriate size
    std::vector<int> vec(size);
    // Fill the vector with sequential values from 10 to 10000 using std::iota
    std::iota(vec.begin(), vec.end(), start);
    // Print the first and last few elements to verify
    std::cout << "First few elements: ";
    std::copy(vec.begin(), vec.begin() + 10, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Last few elements: ";
    std::copy(vec.end() - 10, vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    //----------------------------------------------------------------

    //Try and /or operators
    int a=1,b=0;
    std::cout << "a && b: " << (a and b) << std::endl; // false
    std::cout << "a || b: " << (a or b) << std::endl; // true
    //----------------------------------------------------------------
    
    //calculate accumulate of array
    // Use 0LL for long long to handle large sums
    long long sum = std::accumulate(vec.begin(), vec.end(), 0LL); 
    // Print the result
    std::cout << "Sum of the array elements: " << sum << std::endl;
    //----------------------------------------------------------------
  return 0;
}