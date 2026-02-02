/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alek <alek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:57:45 by adegl-in          #+#    #+#             */
/*   Updated: 2026/02/02 11:50:20 by alek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

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
    std::cout << "\n=== FORM TESTS ===" << std::endl;
    try
	{
        std::cout << "\n=== Form creation ===" << std::endl;
        Form form1("Tax Form", 50, 25);
        std::cout << "Form created: " << form1.getName() << std::endl;
        std::cout << "Grade to sign: " << form1.getGradeToSign() << std::endl;
        std::cout << "Grade to execute: " << form1.getGradeToExecute() << std::endl;
        std::cout << "Is signed: ";
        if (form1.getSign())
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
	{
        std::cout << "\n=== Grade too high (<1) ===" << std::endl;
        Form form2("HighAF", 0, 50);
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
	{
        std::cout << "\n=== Grade too low (>150) ===" << std::endl;
        Form form3("Invalid Form", 50, 151);
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
	{
        std::cout << "\nBureaucrat signs form successfully ===" << std::endl;
        Form form4("Starbucks", 100, 50);
        Bureaucrat worker("Alex", 50);
        std::cout << "Before signing - Form signed: " << (form4.getSign() ? "Yes" : "No") << std::endl;
        worker.signForm(form4);
        std::cout << "After signing - Form signed: " << (form4.getSign() ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
	{
        std::cout << "\n=== Test 5: Bureaucrat fails to sign (grade too low) ===" << std::endl;
        Form form5("Top Secret", 10, 5);
        Bureaucrat intern("Bob", 100);
        std::cout << "Intern grade: " << intern.getGrade() << ", Form requires: " << form5.getGradeToSign() << std::endl;
        intern.signForm(form5);
        std::cout << "Form signed: " << (form5.getSign() ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
	{
        std::cout << "\n=== High-grade bureaucrat signs form ===" << std::endl;
        Form form6("President", 5, 1);
        Bureaucrat boss("Frederiksen", 1);
        std::cout << "Boss grade: " << boss.getGrade() << ", Form requires: " << form6.getGradeToSign() << std::endl;
        boss.signForm(form6);
        std::cout << "Form signed: " << (form6.getSign() ? "Yes" : "No") << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return (0);
}