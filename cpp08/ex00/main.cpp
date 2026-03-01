#include "easyfind.hpp"

int main()
{
	const unsigned int contSize = 67;
	std::list<int> cont(contSize);
	for (size_t i = 0; i < 68; i++)
	{
		cont.push_back(i);
	}
	std::cout << std::endl;
	std::cout << "easyfind(MAX): ";
	easyfind(cont, contSize);
	std::cout << std::endl;
	std::cout << "easyfind(0): ";
	easyfind(cont, 0);
	std::cout << std::endl;
	std::cout << "easyfind(OOB): ";
	easyfind(cont, 69);
	std::cout << std::endl;
	std::cout << "easyfind(negative): ";
	easyfind(cont, -1);
	std::cout << std::endl;
	std::cout << "easyfind(INTMAX): ";
	easyfind(cont, 2147483647);
	std::cout << std::endl;
	std::cout << "easyfind(INTMIN): ";
	easyfind(cont, -2147483647);
	std::cout << std::endl;
	std::cout << "easyfind(alpha): ";
	easyfind(cont, 'a');
	std::cout << std::endl;
	std::cout << "easyfind(consecutive): ";
	easyfind(cont, 6768);
}