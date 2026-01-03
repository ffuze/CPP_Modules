/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:12:10 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:57:04 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPointNumber.hpp"

int main( void )
{
    FixedPointNumber a;
    FixedPointNumber b( a );
    FixedPointNumber c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}