#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    std::cout << "=== identify(Base*) on random instances ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "[" << i << "]";
        Base* ptr = generate();
        std::cout << "Generated class is: ";
        identify(ptr);
        delete (ptr);
    }
    std::cout << std::endl;
    std::cout << "=== identify(Base&) on random instances ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "[" << i << "]";
        Base* ptr = generate();
        std::cout << "Generated class is: ";
        identify(*ptr);
        delete (ptr);
    }
    std::cout << std::endl;
    Base* instances[3] = { new A(), new B(), new C() };
    for (int i = 0; i < 3; i++)
    {
        std::cout << "[" << i << "]";
        std::cout << "pointer: ";
        identify(instances[i]);
        std::cout << "reference: ";
        identify(*instances[i]);
        delete (instances[i]);
    }
    return (0);
}
