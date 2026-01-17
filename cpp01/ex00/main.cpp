/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Alek");
    zombie->announce();
    delete zombie;

    Zombie stackZombie("StackAhhZ");
    stackZombie.announce();

    randomChump("RandomAhhZ");

    Zombie *z1 = newZombie("HeapAhhZ");
    Zombie *z2 = newZombie("HeapAhhZ");
    z1->announce();
    z2->announce();
    delete z1;
    delete z2;
}
