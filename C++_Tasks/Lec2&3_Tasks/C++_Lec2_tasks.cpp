//---------  lec 2 ----------
// author: Ebrahim Mostafa


#include <iostream>
#include <algorithm>

int findMax(int arr[], int size);
bool searchNumber(int arr[], int size, int target);
int deleteNumber(int arr[], int& size, int target);
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]);
void findEvenOdd(int arr[], int size);

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // 1. Find the maximum number in an array
    std::cout << "Maximum number in arr1: " << findMax(arr1, size1) << std::endl;

    // 2. Search for a number in the array (taken from user)
    int numberToSearch;
    std::cout << "Enter a number to search: ";
    std::cin >> numberToSearch;
    std::cout << "Number found: " << (searchNumber(arr1, size1, numberToSearch) ? "Yes" : "No") << std::endl;

    // 3. Delete a number from the array
    std::cout << "Enter a number to delete: ";
    std::cin >> numberToSearch;
    deleteNumber(arr1, size1, numberToSearch);
    std::cout << "Array after deletion: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // 4. Merge arrays
    int mergedArray[10];
    mergeArrays(arr1, size1, arr2, size2, mergedArray);
    std::cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    // 5. Find even and odd numbers in an array
    int size3 = sizeof(mergedArray) / sizeof(mergedArray[0]);
    findEvenOdd(mergedArray, size3);

    // Lambda to calculate the square of a number
    auto square = [](int x) { return x * x; };
    std::cout << "Square of 4: " << square(4) << std::endl;

    // Lambda for sorting
    std::sort(mergedArray, mergedArray + size1 + size2, [](int a, int b) { return a < b; });
    std::cout << "Sorted in ascending order: ";
    for (int i = 0; i < size1 + size2; i++) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    std::sort(mergedArray, mergedArray + size1 + size2, [](int a, int b) { return a > b; });
    std::cout << "Sorted in descending order: ";
    for (int i = 0; i < size1 + size2; i++) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//1-Function to Find the Maximum Number in an Array
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

//2-Function to Search for a Number in the Array (taken from user)
bool searchNumber(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

//3-Function to Delete a Number from the Array
int deleteNumber(int arr[], int& size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            break;
        }
    }
    if (i == size) {
        return size; // Element not found
    }
    // Shift elements to the left
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--; // Reduce array size
    return size;
}

//4-Function to Merge Arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
}

//5-Function to Find Even and Odd Numbers in the Array
void findEvenOdd(int arr[], int size) {
    std::cout << "Even numbers: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\nOdd numbers: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

//Simple Lambda to Calculate the Square of a Given Number
auto square = [](int x) {
    return x * x;
};

//----Sorting with Lambda----
//Ascending Order:
auto ascending = [](int a, int b) {
    return a < b;
};
//Descending Order:
auto descending = [](int a, int b) {
    return a > b;
};
