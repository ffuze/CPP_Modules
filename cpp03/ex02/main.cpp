/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:19:35 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap1("Claude");
	ClapTrap clap2("Gemini");
	ScavTrap scav1("ChatGPT");
	ScavTrap scav2("Deepseek");
	FragTrap frag1("Frag1");
	FragTrap frag2("Frag2");

	// std::cout << std::endl << "=== Attack ===" << std::endl;
	// clap1.attack("Gemini");

	// std::cout << std::endl << "=== Take damage ===" << std::endl;
	// clap2.takeDamage(3);
	// clap2.takeDamage(5);

	// std::cout << std::endl << "=== Repair ===" << std::endl;
	// clap2.beRepaired(2);

	// std::cout << std::endl << "=== Energy ===" << std::endl;
	// for (int i = 0; i < 12; i++)
	// {
	// 	std::cout << "Attack #" << i + 1 << ": ";
	// 	clap1.attack("dummy");
	// }

	// std::cout << std::endl << "=== Lethal damage (>9) ===" << std::endl;
	// clap2.takeDamage(100);

	// std::cout << std::endl << "=== Actions after death ===" << std::endl;
	// clap2.attack("Claude");
	// clap2.beRepaired(12);

	// std::cout << std::endl << "=== Destructors ===" << std::endl;
	
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

	// std::cout << std::endl << "=== Attack ===" << std::endl;
	// scav1.attack("Gemini");

	// std::cout << std::endl << "=== Take damage ===" << std::endl;
	// scav2.takeDamage(3);
	// scav2.takeDamage(5);

	// std::cout << std::endl << "=== Repair ===" << std::endl;
	// scav2.beRepaired(2);

	// std::cout << std::endl << "=== Energy ===" << std::endl;
	// for (int i = 0; i < 67; i++)
	// {
	// 	std::cout << "Attack #" << i + 1 << ": ";
	// 	scav1.attack("dummy");
	// }

	// std::cout << std::endl << "=== Lethal damage (>99) ===" << std::endl;
	// scav2.takeDamage(100);

	// std::cout << std::endl << "=== Actions after death ===" << std::endl;
	// scav2.attack("Claude");
	// scav2.beRepaired(12);

	// std::cout << std::endl << "=== Guard gate keeper ===" << std::endl;
	// scav1.guardGate();
	// scav2.guardGate();

	// std::cout << std::endl << "=== Destructors ===" << std::endl;

	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

	std::cout << std::endl << "=== Attack ===" << std::endl;
	frag1.attack("Gemini");

	std::cout << std::endl << "=== Take damage ===" << std::endl;
	frag2.takeDamage(3);
	frag2.takeDamage(5);

	std::cout << std::endl << "=== Repair ===" << std::endl;
	frag2.beRepaired(2);

	std::cout << std::endl << "=== Energy ===" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Attack #" << i + 1 << ": ";
		frag1.attack("dummy");
	}

	std::cout << std::endl << "=== Lethal damage (>9) ===" << std::endl;
	frag2.takeDamage(100);

	std::cout << std::endl << "=== Actions after death ===" << std::endl;
	frag2.attack("Claude");
	frag2.beRepaired(12);

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	
	return 0;
}
