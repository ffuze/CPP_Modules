/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:19:35 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _health = 100;
    _energy = 50;
    _attack = 20;
    std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_health <= 0)
	{
		std::cout << "Ded, not big surprise" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "ClapTrap says: \"Im tired boss\". " << "Energy: " << _energy << std::endl;
		return;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
    std::cout << _attack << " points of damage! Energy:" << _energy << std::endl;
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
