#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
    int random = rand() % 3;
    if (random == 0)
    {
        std::cout << "Generated type A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated type B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated type C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        // std::cout << "(" << e.what() << ") ";
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        // std::cout << "(" << e.what() << ") ";
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        // std::cout << "(" << e.what() << ") ";
    }
    std::cout << "Unknown type" << std::endl;
}
