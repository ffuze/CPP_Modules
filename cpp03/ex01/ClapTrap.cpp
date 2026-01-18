/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:09:10 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 19:29:26 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	_health = 10;
	_energy = 10;
	_attack = 0;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	ClapTrap::operator=(other);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getAttack() const
{
	return (this->_attack);
}

int ClapTrap::getEnergy() const
{
	return (this->_energy);
}

int ClapTrap::getHealth() const
{
	return (this->_health);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHealth(int health)
{
	this->_health = health;
}

void ClapTrap::setAttack(int attack)
{
	this->_attack = attack;
}

void ClapTrap::setEnergy(int energy)
{
	this->_energy = energy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other.getName();
		_attack = other.getAttack();
		_energy = other.getEnergy();
		_health = other.getHealth();
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_health <= 0)
	{
		std::cout << "Cant make Clap attack if it's dead XD" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "ClapTrap says: \"Im tired boss\". " << "Energy: " << _energy << std::endl;
		return;
	}
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage! Energy: " << _energy << std::endl;
	std::cout << "HP: " << _health << std::endl;
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
	if (_health <= 0)
	{
		_health = 0;
		std::cout << "Headshot!" << std::endl;
		return;
	}
	std::cout << "That hurt! Bigger weapons! HP: "  << _health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "Cant repair ClapTrap if it's already dead lol" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "ClapTrap is out of energy! " << "HP, ENERGY: " << _health << ", " << _energy << std::endl;
		return;
	}
	if (_health >= 10)
	{
		std::cout << "I already have a lot of protein inside me sir!" << std::endl;
		return;
	}
	_energy--;
	_health += amount;
	if (_health > 10)
		_health = 10;
	std::cout << "I need more bullets! Wow, thanks for the protein, sir! Watch me ride that horse sir! -" << _name << " HP: " << _health << std::endl;
}
