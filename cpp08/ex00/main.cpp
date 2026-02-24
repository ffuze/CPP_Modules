#include "easyfind.hpp"

int main()
{
	std::list<int> cont(67);
	for (size_t i = 0; i < 70; i++)
	{
		std::cout << i << std::endl;
		cont.push_back(i);
	}	
	easyfind(cont, 67);
}