/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:14:16 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		void    announce(void);
		void	nameZombie(std::string name);
};
	
Zombie*	zombieHorde(int N, std::string name);
