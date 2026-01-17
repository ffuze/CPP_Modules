/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:28:48 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_raw = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	_raw = value * 256;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	_raw = roundf(value * 256.0f);
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->operator=(obj);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt() const
{
	return (_raw / 256);
}

float Fixed::toFloat() const
{
	 return ((float)_raw / 256.0f);
}

int Fixed::getRawBits(void) const
{
	return (Fixed::_raw);
}

void Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		_raw = obj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed result;
	result.setRawBits(_raw + obj.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed result;
	result.setRawBits(_raw - obj.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed result;
	result.setRawBits(_raw * (obj.getRawBits() / 256));
	return (result);
}

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed result;
	int rawBits = obj.getRawBits();
	if (rawBits == 0)
		return (Fixed(666));
	result.setRawBits(_raw / rawBits);
	return (result);
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->_raw > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->_raw < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->_raw >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->_raw <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->_raw == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->_raw != obj.getRawBits());
}

Fixed& Fixed::operator++()
{
	this->_raw++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_raw++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_raw--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_raw--;
	return (temp);  
}

Fixed& Fixed::min(Fixed &value1, Fixed &value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}

Fixed& Fixed::max(Fixed &value1, Fixed &value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}
