/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:13:57 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _raw;
		static const int _fract = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		Fixed operator+(const Fixed &obj);
		Fixed operator-(const Fixed &obj);
		Fixed operator*(const Fixed &obj);
		Fixed operator/(const Fixed &obj);
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
		Fixed& operator++();
		Fixed operator++(int value);
		Fixed& operator--();
		Fixed operator--(int value);
		static Fixed& min(Fixed& value1, Fixed& value2);
		static const Fixed& min(const Fixed& value1, const Fixed& value2);
		static Fixed& max(Fixed& value1, Fixed& value2);
		static const Fixed& max(const Fixed& value1, const Fixed& value2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
	
