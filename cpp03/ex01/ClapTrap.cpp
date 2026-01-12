#include "ClapTrap.hpp"

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
		std::cout << "Ded, not big surprise" << std::endl;
		return;
	}
	if (_energy < 1)
	{
		std::cout << "ClapTrap says: \"Im tired boss\". Energy: " << _energy<< std::endl;
		return;
	}
	_attack = 5;
	_energy--;
	std::cout << "ClapTrap " << ClapTrap::_name << " attacks " << target << ", causing ";
    std::cout << ClapTrap::_attack << " points of damage! Energy: " << _energy << std::endl;
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
	this->_attack = amount;
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
		std::cout << "Clap is out of energy! " << "HP: " << std::endl;
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