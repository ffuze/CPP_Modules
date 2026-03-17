/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:10:13 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/26 14:58:22 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default Materia created" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Materia has just got destroyed" << std::endl;
}

Ice& Ice::operator=(const Ice &obj)
{
    std::cout << "Operator '=' overload called" << std::endl;
    return (*this);
}

Ice::Ice(const Ice &other) : AMateria(other.type)
{
    Ice::operator=(other);
    std::cout << "Materia copy constructor created" << std::endl;
}

Ice* Ice::clone() const
{
    Ice();
}
