/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:59:56 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/05 19:30:30 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_raw = 0;
    std::cout << "Default constructot called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _raw = obj.getRawBits();
    return (*this);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(obj);
}

int Fixed::getRawBits(void) const
{
    return (std::cout << "getRawBits member function called" << std::endl, Fixed::_raw);
}

void Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}
