#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    std::cout << "=== Generate and identify with pointer ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = generate();
        std::cout << "Identified as: ";
        identify(ptr);
        delete (ptr);
        std::cout << std::endl;
    }
    std::cout << "=== Testing identify with references ===" << std::endl;
    std::cout << std::endl;
    std::cout << "generate() and identify() with reference" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = generate();
        std::cout << "Identified as: ";
        identify(*ptr);
        delete (ptr);
        std::cout << std::endl;
    }
    std::cout << "=== Testing specific instances ===" << std::endl;
    std::cout << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    std::cout << "Instance A with pointer: ";
    identify(a);
    std::cout << "Instance A with reference: ";
    identify(*a);
    std::cout << "Instance B with pointer: ";
    identify(b);
    std::cout << "Instance B with reference: ";
    identify(*b);
    std::cout << "Instance C with pointer: ";
    identify(c);
    std::cout << "Instance C with reference: ";
    identify(*c);
    delete (a);
    delete (b);
    delete (c);
    return (0);
}
