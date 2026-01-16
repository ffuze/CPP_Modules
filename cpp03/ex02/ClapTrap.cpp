/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:11:21 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_attack = 0;
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other.getName();
		_health = other.getHealth();
		_energy = other.getEnergy();
		_attack = other.getAttack();
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHealth() const
{
	return (this->_health);
}

int ClapTrap::getEnergy() const
{
	return (this->_energy);
}

int ClapTrap::getAttack() const
{
	return (this->_attack);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHealth(int health)
{
	this->_health = health;
}

void ClapTrap::setEnergy(int energy)
{
	this->_energy = energy;
}

void ClapTrap::setAttack(int attack)
{
	this->_attack = attack;
}

void ClapTrap::attack(const std::string& target)
{
	if (_health <= 0)
	{
		std::cout << "Ded, not big surprise" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "ClapTrap says: \"Im tired boss\". Energy: " << _energy << std::endl;
		return;
	}
	_attack = 5;
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
    std::cout << _attack << " points of damage! " << std::endl;
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "Hasta la Vista, Baby!" << std::endl;
		return;
	}
	_health -= amount;
	_attack = amount;
	if (_health <= 0)
	{
		std::cout << "Ded, not big surprise" << std::endl;
		return;
	}
	std::cout << "That hurt! Bigger weapons! HP: "  << _health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "Ded, not big surprise" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "Im out of energy! " << "HP: " << std::endl;
		return;
	}
	if (_health + amount > 100)
	{
		std::cout << "I'm still too healthy to be repaired! HP: " << _health << " Amount: " << amount << std::endl;
		return;
	}
	_energy--;
	_health += amount;
	std::cout << "I need more bullets! Wow, thanks for the protein, sir! Watch me ride that horse sir! HP: " << _health << std::endl;
}
