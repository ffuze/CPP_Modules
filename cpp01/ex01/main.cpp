/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:14:16 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
