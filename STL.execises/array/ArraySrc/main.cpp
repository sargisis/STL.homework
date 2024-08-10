#include <iostream>
#include "../ArrayHeader/Array.h"

int main() {
    // Create an array of integers with 5 elements
    g3::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Print the size of the array
    std::cout << "Array size: " << arr.size() << std::endl;

    // Print the elements using operator[]
    std::cout << "Elements of the array: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Modify an element using operator[]
    arr[2] = 10;
    std::cout << "Modified array: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Fill the array with a value
    arr.fill(100);
    std::cout << "Filled array: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Test const_iterator for looping through elements
    std::cout << "Using const_iterator: ";
    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test reverse_iterator for looping through elements in reverse
    std::cout << "Using reverse_iterator: ";
    for (auto rit = arr.rbegin(); rit != arr.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}
