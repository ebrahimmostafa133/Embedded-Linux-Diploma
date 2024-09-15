//---------  lec 4,5 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>
#include <unistd.h> // for sleep function (POSIX)

// Task4: -write string class which has Members { length - string}
class mystr{
    private : 
        std::string str;
        int length;
    public:
        // Constructor
        mystr(std::string input) {
            str = input;
            length = str.length();
        }
        // Getter
        int getLength() {
            return length;
        }

        std::string getString() {
            return str;
        }
};
   //------------------------------------------------------------------------------------------------
//Task5:-handle interrupt signal like (ctrl+c)
void signalHandler(int signum) {
    std::cout << "\nInterrupt signal (" << signum << ") received."<<std::endl;
    // Clean up and close program gracefully
    std::cout << "Gracefully shutting down..."<<std::endl;
    exit(signum);  // Exit the program
}
int main(){

    // Task1: -check if the character is digit ?
    char ch = '5';
    std::cout << (std::isdigit(ch) ? "The charcter is digit." : "The character is not digit.");
   //------------------------------------------------------------------------------------------------
    //task2: -check if all the array is even ?
    int arr[] = {2, 4, 6, 8, 10};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << (std::all_of(arr, arr + size, [](int i) { return i % 2 == 0; }) ? "All elements are even." : "Not all elements are even.");
    std::cout << std::endl;
    //------------------------------------------------------------------------------------------------
    // task3: -check if there is any value of array is even ?
    std::cout << (std::any_of(arr, arr + size, [](int i) { return i % 2 == 0; }) ? "There is an even value in the array." : "No even value in the array.");
    std::cout << std::endl;
    //------------------------------------------------------------------------------------------------
    //Task4:
    mystr myString("Hello World");
    std::cout << "Length of the string: " << myString.getLength() << std::endl;
    std::cout << "The string: " << myString.getString() << std::endl;
    //------------------------------------------------------------------------------------------------
    //Task5:
    signal(SIGINT, signalHandler);
    while(true){
        std::cout << "Running program... Press Ctrl+C to interrupt."<< std::endl;
        sleep(2); // Sleep for 1 second before printing again
    }
    //------------------------------------------------------------------------------------------------
    return 0;
}

