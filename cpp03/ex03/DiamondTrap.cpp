#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_attack = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	std::cout << "DiamohdTrap copy constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << ClapTrap::_name << ", but everybody calls me " << _name << std::endl;
}