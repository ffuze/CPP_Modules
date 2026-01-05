/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:14:16 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::announce()
{
    std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::nameZombie(std::string name)
{
    Zombie::_name = name;
}

Zombie::~Zombie()
{
    std::cout << Zombie::_name << " was caught lackin'..." << std::endl;
}
