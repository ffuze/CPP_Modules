#include "Zombie.hpp"

int main(void)
{
	int number = 12;
	std::string name = "Alek";
	Zombie* zombie = zombieHorde(number, name);
	if (!zombie)
		return (0);
	for (int i = 0; i < number; i++)
	{
		zombie[i].announce();
	}
	delete[] zombie;
	return (1);
}