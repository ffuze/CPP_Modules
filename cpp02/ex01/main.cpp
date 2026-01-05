/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:12:10 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/05 15:30:24 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPointNumber.hpp"

int main( void ) {
    FixedPointNumber a;
    FixedPointNumber const b( 10 );
    FixedPointNumber const c( 42.42f );
    FixedPointNumber const d( b );
    a = FixedPointNumber( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}