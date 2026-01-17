/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int number = 12;
	std::string name = "Alek";
	Zombie* zombie = zombieHorde(number, name);
	if (zombie)
	{
		for (int i = 0; i < number; i++)
			zombie[i].announce();
		delete[] zombie;
	}

	Zombie* single = zombieHorde(1, "Solo");
	if (single)
	{
		single[0].announce();
		delete[] single;
	}

	Zombie* none = zombieHorde(0, "Nobody");
	if (none)
		delete[] none;

	Zombie* diff = zombieHorde(5, "Brains");
	if (diff)
	{
		for (int i = 0; i < 5; i++)
			diff[i].announce();
		delete[] diff;
	}
	return 0;
}
