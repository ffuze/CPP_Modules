/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointNumber.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:13:57 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/05 19:09:01 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

class FixedPointNumber
{
	private:
		int _raw;
		static const int _fract = 8;
	public:
		FixedPointNumber();
		FixedPointNumber(const int value);
		FixedPointNumber(const float value);
		~FixedPointNumber();
		FixedPointNumber(const FixedPointNumber &obj);
		FixedPointNumber &operator=(const FixedPointNumber &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	};

std::ostream &operator<<(std::ostream &os, const FixedPointNumber &obj);
	