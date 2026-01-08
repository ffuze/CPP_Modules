#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
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
		_health = 0;
	std::cout << "That hurt! Bigger weapons! HP: "  << _health << std::endl;
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
		std::cout << "ClapTrap is out of energy! " << "HP: " << _health << std::endl;
		return;
	}
	_energy--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage! " << "HP: " << _health << std::endl;
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
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
		std::cout << "Clap is out of energy! " << "HP: " << std::endl;
		return;
	}
	if (_health + amount > 10)
	{
		std::cout << "I'm still too healthy to be repaired! HP: " << _health << " Amount: " << amount << std::endl;
		return;
	}
	_energy--;
	_health += amount;
	std::cout << "I need more bullets! Wow, thanks for the protein, sir! Watch me ride that horse sir! HP: " << _health << std::endl;
}