
#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {

    std::vector<int> numbers;
    int result;

    for (int i=1; i<=10; i++) {
        numbers.push_back(i);
    }

    // Test1 - This one will be succesfull, 3 will be founded
    try {
        result = easyfind(numbers, 3);
        std::cout << GREEN "\nThe number " << result << " is in the vector\n" << DEFAULT << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << MAGENTA << "\nThe number is not in the vector\n" << DEFAULT << std::endl;
    }

    // Test2 - This one will be succesfull, 10 will be founded
    try {
        result = easyfind(numbers, 10);
        std::cout << GREEN "\nThe number " << result << " is in the vector\n" << DEFAULT << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << MAGENTA << "\nThe number is not in the vector\n" << DEFAULT << std::endl;
    }

    // Test3 - This one will fail, 11 is not in the vector
    try {
        result = easyfind(numbers, 11);
        std::cout << GREEN "\nThe number " << result << " is in the vector\n" << DEFAULT << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << MAGENTA << "\nThe number 11 is not in the vector\n" << DEFAULT << std::endl;
    }
    return 0;
}