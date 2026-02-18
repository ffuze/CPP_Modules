#include "templates.hpp"

int main()
{
    std::cout << "Max of 5 and 5 is: " << myMax<int>(5, 5) << std::endl;
    std::cout << "Max of 3.5 and 7.5 is: " << myMax<double>(3.5, 7.5) << std::endl;
    std::cout << "Max of 'g' and 'e' is: " << myMax<char>('g', 'e') << std::endl;
    
    std::cout << "Min of 5 and 5 is: " << myMin<int>(5, 5) << std::endl;
    std::cout << "Min of 3.5 and 7.5 is: " << myMin<double>(3.5, 7.5) << std::endl;
    std::cout << "Min of 'g' and 'e' is: " << myMin<char>('g', 'e') << std::endl;

    int a = 6;
    int b = 7;
    std::cout << "Before: a = " << a << ", b = " << b << std::endl;
    mySwap(a, b);
    std::cout << "Now: a = " << a << ", b = " << b << std::endl;

    return 0;
}