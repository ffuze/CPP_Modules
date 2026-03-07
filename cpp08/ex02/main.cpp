#include "MutantStack.hpp"
#include <algorithm>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl; // 17

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "=== Container content: ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    if (!mstack.empty())
    {
        MutantStack<int>::iterator last = mstack.end() - 1; 
        std::cout << "Element on tail found: " << *last << std::endl;
    }

    std::cout << "=== Reversed container content ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    for (; rit != rite; ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return (0);
}