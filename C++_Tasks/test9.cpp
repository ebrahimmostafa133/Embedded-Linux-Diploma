#include<bits/stdc++.h>

class EnhansedString :public std::string{
    public:
        using std::string::string;
        void to_upper(){
            std::string str;
            std::transform(this->begin(), this->end(),this->begin(),::toupper);
        }
        void to_lower(){
            std::transform(this->begin(), this->end(), this->begin(),::tolower);
        }
};

template<typename T>void print(const T & value){
    std::cout<<value<<std::endl;
}


template <typename T>
void display(const T &v) {
    for (const auto &elem : v) {
        std::cout << elem << " ";  // Print each element
    }
    std::cout << std::endl;  // End the line after printing all elements
}

template<typename T>void print_vector(const std::vector<T> &v){
    for(const auto &elem :v){
        std::cout<<elem<< " ";
    }
    std::cout<<std::endl;
}

constexpr int MAX_SIZE = 7;
class String : public std::array<char, MAX_SIZE>{
    public:
    String(const char *str){
        strncpy(data(), str, strlen(str));
    }
    void print()const{
        std::for_each(begin(), end(),[](char c){std::cout<<c<<" ";});
        }
};
int main(){
    // Using a raw string literal
    std::string path = R"(C:\Users\Example\Documents\file.txt)";
    std::cout << "File path: " << path << std::endl;
    //----------------------------------------------------------------
    EnhansedString s="Hallo benzema";
    s.to_upper();
    std::cout << "Uppercase: " << s << std::endl;
    s.to_lower();
    std::cout << "Lowercase: " << s << std::endl;
    //----------------------------------------------------------------
    std::array<int,5>arr={1,2,3,4,5};
    print(arr.size());
    print(arr.front());
    print(arr.back());
    print(arr.max_size());
    arr.at(2)=12;
    for(auto &i:arr){
        print(i);
    }
    //----------------------------------------------------------------
    using commands = std::vector<std::string>;
    commands keyboard = {
        "type C:\\Windows\\System32\\drivers\\etc\\hosts",   // equivalent to /etc/hosts
        "systeminfo",  // provides system information
        "wmic os get caption",  // gets the operating system name
        "type C:\\Windows\\System32\\config\\systemprofile\\AppData\\Local\\Microsoft\\Windows\\UsrClass.dat"  // a random file, replace with a file of your choice
    };
    // Loop through the commands and execute them
    /*for (const auto &command : keyboard) {
        if (!command.empty()) {
            std::system(command.c_str()); // Execute the command
        }
    }*/
    //----------------------------------------------------------------
    String x("Benzema");
    x.print();
    //----------------------------------------------------------------
    std::vector<int> v2 = {1, 2, 3, -3, 4, 5}; // vector initialized with list of values
    std::vector<int> v3(v2);
    std::vector<int> v4(std::move(v3)); // Move constructor (v3 is now empty)
    std::vector<int> v5(4, 100);  // 4 elements with value 100
    std::vector<int> v6(arr.begin(), arr.end());  // vector initialized with range from array
    // Print the vectors
    print_vector(v4); // v4 contains values from v3
    print_vector(v5); // v5 contains four 100's
    print_vector(v6); // v6 contains values copied from the array

    std::vector<int> v = {1, 2, 3, -3, 4, 5};
    // Adding elements to the vector
    v.push_back(6);               // Adds element 6 at the end
    v.emplace_back(12);            // Adds element 12 at the end (optimized version of push_back)
    v.insert(v.begin(), 20);       // Inserts element 20 at the beginning of the vector
    // Assign new values to the vector
    v.assign({-1, -3, 4, 5});      // Assigns new values to the vector, replacing old ones
    std::vector<int> v7 = {-5, -6, -8, -9};  // Initialize another vector
    v.insert(v.end(), v7.begin(), v7.end()); // Insert elements of v2 at the end of v
    // Erase an element from the vector
    v.erase(v.begin() + 1);  // Removes the second element from the vector
    v.assign(4, 100);  // Assigns 4 elements, each having the value 100
    std::cout << "Final vector v: ";
    print_vector(v);


     std::string vv{"Benzema"};

    // Display the initial size and capacity of the string
    std::cout << "Initial size: " << vv.size() << std::endl;
    std::cout << "Initial capacity: " << vv.capacity() << std::endl;

    // Display the memory location of the string's data
    std::cout << "Initial memory location: " << static_cast<const void*>(vv.data()) << std::endl;

    // Initialize another string with some text
    std::string st("the best player");

    // Insert the second string into the first one at the end
    vv.insert(vv.end(), st.begin(), st.end());

    // Display the size, capacity, and memory location after insertion
    std::cout << "Size after insertion: " << vv.size() << std::endl;
    std::cout << "Capacity after insertion: " << vv.capacity() << std::endl;
    std::cout << "Memory location after insertion: " << static_cast<const void*>(vv.data()) << std::endl;
    //----------------------------------------------------------------
    std::set<int> w = {-11, -31, -4,5,5, 41};  // Properly initializing the set
    w.insert(6);  // Insert an additional element into the set

    display(w);  // Print the set

    // Find an element in the set
    auto it = w.find(2);  // Search for the value '2'
    if (it == w.end()) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found " << *it << std::endl;
    }






    return 0;
}

