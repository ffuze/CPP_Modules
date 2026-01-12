/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:28:48 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/12 12:35:32 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    _raw = value * 256;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _raw = roundf(value * 256.0f);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(obj);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt() const
{
    return (_raw / 256);
}

float Fixed::toFloat() const
{
     return ((float)_raw / 256.0f);
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _raw = obj.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}

int Fixed::getRawBits(void) const
{
    return (Fixed::_raw);
}

void Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}
