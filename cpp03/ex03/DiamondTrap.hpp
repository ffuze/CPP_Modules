#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& obj); 
		DiamondTrap(const DiamondTrap& other);
		void attack(const std::string& target);
		void whoAmI();
};

#endif