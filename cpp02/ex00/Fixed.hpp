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

class Fixed
{
	private:
		int _raw;
		static const int _fract = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
