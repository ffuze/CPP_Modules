/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:18:54 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 18:09:35 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap robot1("Claude");
	ClapTrap robot2("Gemini");

	std::cout << std::endl << "=== attack() ===" << std::endl;
	robot1.attack("Gemini");

	std::cout << std::endl << "=== takeDamage() ===" << std::endl;
	robot2.takeDamage(3);
	robot2.takeDamage(5);

	std::cout << std::endl << "=== beRepaired() ===" << std::endl;
	robot2.beRepaired(2);

	std::cout << std::endl << "=== energy ===" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Attack " << i + 1 << ": ";
		robot1.attack("dummy");
		robot1.beRepaired(1);
	}

	std::cout << std::endl << "=== lethal damage ===" << std::endl;
	robot2.takeDamage(100);

	std::cout << std::endl << "=== actions after death ===" << std::endl;
	robot2.attack("Claude");
	robot2.beRepaired(12);

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	return 0;
}
