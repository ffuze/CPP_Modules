/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:20:00 by adegl-in          #+#    #+#             */
/*   Updated: 2026/02/02 17:32:22 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n=== Shrubbery creation ===" << std::endl;
    try
    {
        Bureaucrat bur1("Alek", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bur1 << std::endl;
        std::cout << "Form: " << shrub.getName() << " (sign: " << shrub.getGradeToSign() 
                  << ", exec: " << shrub.getGradeToExecute() << ")" << std::endl;
        bur1.signForm(shrub);
        bur1.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bur2("Ilyas", 140);
        ShrubberyCreationForm shrub("garden");
        std::cout << bur2 << std::endl;
        bur2.signForm(shrub);
        bur2.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Robotomy request ===" << std::endl;
    try
    {
        Bureaucrat bur2("Leo", 40);
        RobotomyRequestForm robot1("Bender");
        
        std::cout << bur2 << std::endl;
        std::cout << "Form: " << robot1.getName() << " (sign: " << robot1.getGradeToSign() 
                  << ", exec: " << robot1.getGradeToExecute() << ")" << std::endl;
        
        bur2.signForm(robot1);
        bur2.executeForm(robot1);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Robotomy request with multiple attempts ===" << std::endl;
    try
    {
        Bureaucrat bur3("Thil", 1);
        RobotomyRequestForm robot("Target");
        
        bur3.signForm(robot);
        std::cout << "\nAttempt 1:" << std::endl;
        bur3.executeForm(robot);
        std::cout << "\nAttempt 2:" << std::endl;
        bur3.executeForm(robot);
        std::cout << "\nAttempt 3:" << std::endl;
        bur3.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Robotomy request with grade too low ===" << std::endl;
    try
    {
        Bureaucrat bur4("Xhul", 50);
        RobotomyRequestForm robot("R2D2");
        
        std::cout << bur4 << std::endl;
        bur4.signForm(robot);
        bur4.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Presidential Pardon ===" << std::endl;
    try
    {
        Bureaucrat president("Brimstone", 1);
        PresidentialPardonForm pardon("Breach");
        
        std::cout << president << std::endl;
        std::cout << "Form: " << pardon.getName() << " (sign: " << pardon.getGradeToSign() 
                  << ", exec: " << pardon.getGradeToExecute() << ")" << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Presidential pardon with sign failure ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 30);
        PresidentialPardonForm pardon("Ford Prefect");
        
        std::cout << intern << std::endl;
        intern.signForm(pardon);
        intern.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Execute UNSIGNED Form ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("unsigned");
        
        std::cout << boss << std::endl;
        std::cout << "Trying to execute without signing..." << std::endl;
        boss.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== All forms with grade 1 bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat god("God", 1);
        ShrubberyCreationForm shrub("perfect");
        RobotomyRequestForm robot("Perfect Target");
        PresidentialPardonForm pardon("Lucky Person");
        std::cout << god << std::endl;
        std::cout << "\n--- Shrubbery ---" << std::endl;
        god.signForm(shrub);
        god.executeForm(shrub);
        std::cout << "\n--- Robotomy ---" << std::endl;
        god.signForm(robot);
        god.executeForm(robot);
        
        std::cout << "\n--- Pardon ---" << std::endl;
        god.signForm(pardon);
        god.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
