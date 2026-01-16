/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:55:15 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap
{
	private:
		std::string _name;
		int _health;
		int _energy;
		int _attack;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		int getHealth(void) const;
		int getEnergy(void) const;
		int getAttack(void) const;
		void setName(std::string name);
		void setHealth(int health);
		void setEnergy(int energy);
		void setAttack(int attack);
};
