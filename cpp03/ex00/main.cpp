/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:18:54 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap robot1("Claude");
	ClapTrap robot2("Gemini");

	std::cout << std::endl << "=== Testing Attack ===" << std::endl;
	robot1.attack("Gemini");
	std::cout << std::endl;

	std::cout << std::endl << "=== Testing Take Damage ===" << std::endl;
	robot2.takeDamage(3);
	robot2.takeDamage(5);

	std::cout << std::endl << "=== Testing Repair ===" << std::endl;
	robot2.beRepaired(2);

	std::cout << std::endl << "=== Testing Energy Drain ===" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Attack #" << i + 1 << ": ";
		robot1.attack("dummy");
	}

	std::cout << std::endl << "=== Testing Lethal Damage ===" << std::endl;
	robot2.takeDamage(100);

	std::cout << std::endl << "=== Testing Actions After Death ===" << std::endl;
	robot2.attack("Claude");
	robot2.beRepaired(12);

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	return 0;
}
