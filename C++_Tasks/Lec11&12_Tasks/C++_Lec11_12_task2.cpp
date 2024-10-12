//---------  lec 11,12 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>
//---------------------- Task2 ----------------------
/*
Copying Ranges
Sequence Reordering
Changing
std/algorithms/reordering_ht
Removing
Numeric Operations
Sorted Sequence Operations
Binary Heap Operations
Composable Range Views
Special Containers
Special Iterators
Random Numbers
*/
// Utility function to print containers
template <typename T>
void printContainer(const T& container) {
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
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

    return 0;
}