#include "easyfind.hpp"

int main()
{
    std::vector<int> cont(67, 1);
    std::cout << "Capacita' allocata dal vector: " << cont.capacity() << std::endl;
    std::cout << "Capacita' occupata dal vector: " << cont.size() << std::endl;
}