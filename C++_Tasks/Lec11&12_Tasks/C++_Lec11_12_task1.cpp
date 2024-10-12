//---------  lec 11,12 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>
#include <span>

//---------------------- Task1 ----------------------
//Circular Referencing --> Weak_ptr
std::weak_ptr<int> gw;
void observe()
{
    std::cout << "gw.use_count() == " << gw.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> spt = gw.lock())
        std::cout << "*spt == " << *spt << '\n';
    else
        std::cout << "gw is expired\n";
}
//---------------------- Task2 ----------------------
/*
Iterators
Sequence Containers
Sequence Views
Associative Containers
Algorithms Introduction
Container Traversal
Minimum / Maximum
Existence Queries
Finding Elements
Comparing Ranges
*/
// Utility function to print containers
template <typename T>
void printContainer(const T& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        observe();
    }
    observe();
    //----------------------------------------------------------------
    // Create a shared_ptr managing an int
    std::shared_ptr<int> sp1 = std::make_shared<int>(100);
    std::cout << "sp1 points to: " << *sp1 << std::endl;
    // Create a weak_ptr from the shared_ptr
    std::weak_ptr<int> wp1 = sp1;
    // Check if weak_ptr can be locked (i.e., shared_ptr is still valid)
    if (auto sp = wp1.lock()) {
        std::cout << "wp1 points to: " << *sp << std::endl;
    } else {
        std::cout << "wp1 points to nothing." << std::endl;
    }
    // Create another shared_ptr and weak_ptr
    std::shared_ptr<int> sp2 = std::make_shared<int>(200);
    std::weak_ptr<int> wp2;
    // Assign wp2 from another weak_ptr
    wp2 = wp1;
    if (auto sp = wp2.lock()) {
        std::cout << "After assignment, wp2 points to: " << *sp << std::endl;
    } else {
        std::cout << "After assignment, wp2 points to nothing." << std::endl;
    }
    // Move assignment from a weak_ptr
    std::weak_ptr<int> wp3 = std::move(wp1);
    if (auto sp = wp3.lock()) {
        std::cout << "After move, wp3 points to: " << *sp << std::endl;
    } else {
        std::cout << "After move, wp3 points to nothing." << std::endl;
    }
    // Check if wp1 is now empty after move
    if (auto sp = wp1.lock()) {
        std::cout << "wp1 still points to: " << *sp << std::endl;
    } else {
        std::cout << "wp1 now points to nothing." << std::endl;
    }
    //----------------------------------------------------------------
    // 1. Iterators with Sequence Containers
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "Vector elements using iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Range-based for loop (also iterator-based traversal)
    std::cout << "Vector elements using range-based for loop: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // 2. Sequence Containers
    std::array<int, 5> arr = {1, 2, 3, 4, 5};  // Fixed size container
    std::list<int> lst = {5, 10, 15, 20};      // Doubly linked list
    std::deque<int> dq = {100, 200, 300};      // Double-ended queue

    std::cout << "Array elements: ";
    printContainer(arr);
    std::cout << "List elements: ";
    printContainer(lst);
    std::cout << "Deque elements: ";
    printContainer(dq);

    // 3. Sequence Views (std::span and std::string_view)
    std::span<int> spanVec(vec.data(), vec.size());  // Pass the pointer and size of the vector
    std::cout << "Span of vector: ";
    printContainer(spanVec);

    std::string_view strView = "Hello, World!";
    std::cout << "String view: " << strView << "\n";

    // 4. Associative Containers (Set, Map)
    std::set<int> mySet = {10, 20, 30, 40};            // Sorted set
    std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};  // Key-value pairs

    std::cout << "Set elements: ";
    printContainer(mySet);
    std::cout << "Map elements: \n";
    for (const auto& [key, value] : myMap) {
        std::cout << key << " => " << value << "\n";
    }

    // 5. Algorithms Introduction
    // Non-modifying algorithms
    std::cout << "Count of 20 in vector: " << std::count(vec.begin(), vec.end(), 20) << "\n";
    
    // Modifying algorithms
    std::vector<int> vecCopy(5);
    std::copy(vec.begin(), vec.end(), vecCopy.begin());
    std::cout << "Copied vector: ";
    printContainer(vecCopy);

    // Sorting
    std::sort(vecCopy.begin(), vecCopy.end(), std::greater<int>());
    std::cout << "Sorted vector in descending order: ";
    printContainer(vecCopy);

    // 6. Minimum/Maximum
    std::cout << "Min element in vector: " << *std::min_element(vec.begin(), vec.end()) << "\n";
    std::cout << "Max element in vector: " << *std::max_element(vec.begin(), vec.end()) << "\n";

    // 7. Existence Queries (std::find, std::any_of, std::none_of)
    auto it = std::find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        std::cout << "Found element 30 in vector.\n";
    }

    bool hasLargeElement = std::any_of(vec.begin(), vec.end(), [](int x) { return x > 35; });
    std::cout << "Any element greater than 35: " << (hasLargeElement ? "Yes" : "No") << "\n";

    // 8. Finding Elements
    it = std::find_if(vec.begin(), vec.end(), [](int x) { return x % 3 == 0; });
    if (it != vec.end()) {
        std::cout << "Found element divisible by 3: " << *it << "\n";
    }

    // 9. Comparing Ranges (std::equal)
    std::vector<int> vec2 = {10, 20, 30, 40, 50};
    bool isEqual = std::equal(vec.begin(), vec.end(), vec2.begin());
    std::cout << "Vectors are equal: " << (isEqual ? "Yes" : "No") << "\n";

    // Lexicographical compare
    std::string str1 = "apple", str2 = "banana";
    bool isLexicographicallySmaller = std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end());
    std::cout << "Is 'apple' lexicographically smaller than 'banana': " << (isLexicographicallySmaller ? "Yes" : "No") << "\n";

    // 10. Tuples and Pairs
    std::pair<int, std::string> myPair(42, "Hello");
    std::cout << "Pair elements: " << myPair.first << ", " << myPair.second << "\n";

    std::tuple<int, std::string, double> myTuple(10, "Tuple", 3.14);
    std::cout << "Tuple elements: " << std::get<0>(myTuple) << ", " << std::get<1>(myTuple) << ", " << std::get<2>(myTuple) << "\n";

    // Modify tuple elements
    std::get<0>(myTuple) = 100;
    std::get<1>(myTuple) = "Modified Tuple";
    std::cout << "Modified Tuple: " << std::get<0>(myTuple) << ", " << std::get<1>(myTuple) << ", " << std::get<2>(myTuple) << "\n";

    //----------------------------------------------------------------

    // Vectors with new names
    std::vector<int> numbers1 = {10, 20, 30, 40, 50};
    std::vector<int> numbers2 = {60, 70, 80, 90, 100};

    // 1. Copying Ranges
    std::vector<int> numbersCopy(5);
    std::copy(numbers1.begin(), numbers1.end(), numbersCopy.begin());
    std::cout << "Copied numbers1 to numbersCopy: ";
    printContainer(numbersCopy);

    // 2. Sequence Reordering (std::reverse, std::rotate, std::shuffle)
    std::reverse(numbers1.begin(), numbers1.end());
    std::cout << "Reversed numbers1: ";
    printContainer(numbers1);

    std::rotate(numbers1.begin(), numbers1.begin() + 2, numbers1.end());
    std::cout << "Rotated numbers1: ";
    printContainer(numbers1);

    // Shuffle numbers1 (requires random generator)
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers1.begin(), numbers1.end(), g);
    std::cout << "Shuffled numbers1: ";
    printContainer(numbers1);

    // 3. Changing Elements (std::replace)
    std::replace(numbers1.begin(), numbers1.end(), 10, 99);  // Replace 10 with 99
    std::cout << "numbers1 after replacing 10 with 99: ";
    printContainer(numbers1);

    // 4. Removing Elements (std::remove, std::erase for vector)
    numbers1.erase(std::remove(numbers1.begin(), numbers1.end(), 99), numbers1.end());
    std::cout << "numbers1 after removing 99: ";
    printContainer(numbers1);

    // 5. Numeric Operations (std::accumulate, std::iota)
    int sum = std::accumulate(numbers1.begin(), numbers1.end(), 0);
    std::cout << "Sum of numbers1 elements: " << sum << "\n";

    std::iota(numbers1.begin(), numbers1.end(), 1);  // Fill with sequential values starting from 1
    std::cout << "numbers1 after std::iota: ";
    printContainer(numbers1);

    // 6. Sorted Sequence Operations (std::sort, std::binary_search, std::lower_bound, std::upper_bound)
    std::sort(numbers1.begin(), numbers1.end());
    std::cout << "Sorted numbers1: ";
    printContainer(numbers1);

    bool found = std::binary_search(numbers1.begin(), numbers1.end(), 3);
    std::cout << "Binary search for 3: " << (found ? "Found" : "Not found") << "\n";

    auto lower = std::lower_bound(numbers1.begin(), numbers1.end(), 3);
    auto upper = std::upper_bound(numbers1.begin(), numbers1.end(), 3);
    std::cout << "Lower bound of 3: " << (lower - numbers1.begin()) << "\n";
    std::cout << "Upper bound of 3: " << (upper - numbers1.begin()) << "\n";

    // 7. Binary Heap Operations (std::push_heap, std::pop_heap, std::make_heap)
    std::vector<int> heapNumbers = {30, 10, 50, 20, 40};
    std::make_heap(heapNumbers.begin(), heapNumbers.end());
    std::cout << "Heap after make_heap: ";
    printContainer(heapNumbers);

    std::pop_heap(heapNumbers.begin(), heapNumbers.end());
    std::cout << "Heap after pop_heap (max moved to end): ";
    printContainer(heapNumbers);

    heapNumbers.push_back(60);
    std::push_heap(heapNumbers.begin(), heapNumbers.end());
    std::cout << "Heap after push_heap (60 added): ";
    printContainer(heapNumbers);

    // 8. Special Containers (std::deque, std::list)
    std::deque<int> dequeNumbers = {10, 20, 30};
    dequeNumbers.push_front(5);
    dequeNumbers.push_back(35);
    std::cout << "Deque elements: ";
    printContainer(dequeNumbers);

    std::list<int> listNumbers = {100, 200, 300};
    listNumbers.push_front(50);
    listNumbers.push_back(400);
    std::cout << "List elements: ";
    printContainer(listNumbers);

    // 9. Special Iterators (std::back_inserter, std::inserter, std::istream_iterator, std::ostream_iterator)
    std::vector<int> newNumbers;
    std::copy(numbers1.begin(), numbers1.end(), std::back_inserter(newNumbers));
    std::cout << "New vector after back_inserter: ";
    printContainer(newNumbers);

    // 10. Random Numbers (std::random_device, std::mt19937, std::uniform_int_distribution)
    std::random_device rd2;
    std::mt19937 gen(rd2());
    std::uniform_int_distribution<> dis(1, 100);
    
    std::cout << "Random numbers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << dis(gen) << " ";
    }
    std::cout << "\n";
}

