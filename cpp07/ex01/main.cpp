#include "iter.hpp"

template <typename T>
static void printValue(T& value)
{
    std::cout << value << std::endl;
}

template <typename T>
static void incrementValue(T& value)
{
    value++;
}

template <typename T>
static void doubleValue(T& value)
{
    value *= 2;
}

int main()
{
    char array[] = "Chamber";
    iter(array, 7, &printValue<char>);
    std::cout << std::endl;

    int numbers[] = {1, 2, 3, 4, 5};
    iter(numbers, 5, &printValue<int>);
    std::cout << std::endl;

    std::cout << "Before: ";
    iter(numbers, 5, &printValue<int>);
    iter(numbers, 5, &incrementValue<int>);
    std::cout << "After: ";
    iter(numbers, 5, &printValue<int>);
    std::cout << std::endl;

    double decimals[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "BEfore: ";
    iter(decimals, 5, &printValue<double>);
    iter(decimals, 5, &doubleValue<double>);
    std::cout << "After: ";
    iter(decimals, 5, &printValue<double>);
    std::cout << std::endl;

    std::string words[] = {"OPEN", "UP", "THE", "SKYE"};
    iter(words, 4, &printValue<std::string>);
    std::cout << std::endl;
    
    return (0);
}