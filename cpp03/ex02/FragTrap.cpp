/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:19:35 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 19:26:01 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    _name = name;
    _health = 100;
    _energy = 100;
    _attack = 30;
    std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " wants to cutely high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_health <= 0)
	{
		std::cout << "Cant make FragTrap attack if it's dead XD" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "FragTrap says: \"Im tired boss\". " << "Energy: " << _energy << std::endl;
		return;
	}
	_energy--;
	std::cout << "FragTrap " << FragTrap::_name << " attacks " << target << ", causing ";
    std::cout << FragTrap::_attack << " points of damage! Energy:" << _energy << std::endl;
	std::cout << "HP: " << _health << std::endl;
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
}
