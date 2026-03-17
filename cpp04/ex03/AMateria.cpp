/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:03:53 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/26 14:58:22 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type("default")
{
    std::cout << "Default Materia created" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Materia has just got destroyed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
    std::cout << "Operator '=' overload called" << std::endl;
    return (*this);
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
    AMateria::operator=(other);
    std::cout << "Materia copy constructor created" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (type);
}
