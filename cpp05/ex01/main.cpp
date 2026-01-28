/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:57:45 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/26 19:37:41 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(void)
{
	try
	{
        std::cout << "=== Valid bureaucrat (grade 150) ===" << std::endl;
        Bureaucrat b1("Giuliano", 150);
        std::cout << b1 << std::endl;
        std::cout << "Decreasing grade..." << std::endl;
        b1.decreaseGrade();
        std::cout << b1 << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        std::cout << "=== Invalid bureaucrat (grade 151) ===" << std::endl;
        Bureaucrat b2("Ilias", 151);
        std::cout << b2 << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        std::cout << "=== Valid bureaucrat ===" << std::endl;
        Bureaucrat b3("Tilina", 67);
        std::cout << b3 << std::endl;
        b3.increaseGrade();
        std::cout << "After increase: " << b3 << std::endl;
        b3.decreaseGrade();
        std::cout << "After decrease: " << b3 << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        std::cout << "=== Test 4: Invalid bureaucrat (grade -1) ===" << std::endl;
        Bureaucrat b4("Alec", -1);
        std::cout << b4 << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
	{
        std::cout << "=== Valid bureaucrat at grade 1 ===" << std::endl;
        Bureaucrat b5("Boss", 1);
        std::cout << b5 << std::endl;
        b5.increaseGrade();
        std::cout << b5 << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}