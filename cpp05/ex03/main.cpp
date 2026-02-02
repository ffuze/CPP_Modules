/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:00:00 by adegl-in          #+#    #+#             */
/*   Updated: 2026/02/02 18:54:56 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n=== Create shrubbery creation form ===\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << "Form created: " << form->getName() << std::endl;
			std::cout << "  - Sign grade: " << form->getGradeToSign() << std::endl;
			std::cout << "  - Exec grade: " << form->getGradeToExecute() << std::endl;
			Bureaucrat alek("Alek", 130);
			alek.signForm(*form);
			alek.executeForm(*form);
			delete (form);
		}
	}
	std::cout << "\n=== Create robotomy request form ---\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << "Form created: " << form->getName() << std::endl;
			std::cout << "  - Sign grade: " << form->getGradeToSign() << std::endl;
			std::cout << "  - Exec grade: " << form->getGradeToExecute() << std::endl;
			Bureaucrat alek("Alek", 40);
			alek.signForm(*form);
			alek.executeForm(*form);
			delete (form);
		}
	}
	std::cout << "\n=== Create presidential pardon form ===\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		form = someRandomIntern.makeForm("presidential pardon", "Breach");
		if (form)
		{
			std::cout << "Form created: " << form->getName() << std::endl;
			std::cout << "  - Sign grade: " << form->getGradeToSign() << std::endl;
			std::cout << "  - Exec grade: " << form->getGradeToExecute() << std::endl;
			Bureaucrat president("President", 1);
			president.signForm(*form);
			president.executeForm(*form);
			delete (form);
		}
	}
	std::cout << "\n=== TEST 4: Case Insensitive Names ---\n" << std::endl;
	{
		Intern intern;
		AForm* form1 = intern.makeForm("SHRUBBERY CREATION", "garden");
		AForm* form2 = intern.makeForm("RoBoToMy ReQuEsT", "target");
		AForm* form3 = intern.makeForm("Presidential Pardon", "someone");
		
		if (form1)
		{
			std::cout << "Created: " << form1->getName() << std::endl;
			delete form1;
		}
		if (form2)
		{
			std::cout << "Created: " << form2->getName() << std::endl;
			delete form2;
		}
		if (form3)
		{
			std::cout << "Created: " << form3->getName() << std::endl;
			delete form3;
		}
	}
	std::cout << "\n=== Invalid form name ===\n" << std::endl;
	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("invalid form", "target");
		if (!form)
			std::cout << "Yup it returns NULL" << std::endl;
		form = intern.makeForm("tax evasion form", "IRS");
		if (!form)
			std::cout << "Yup it returns NULL" << std::endl;
	}
	std::cout << "\n=== Multiple forms from same intern ===\n" << std::endl;
	{
		Intern intern;
		Bureaucrat god("God", 1);
		std::cout << "Creating 3 different forms:\n" << std::endl;
		AForm* form1 = intern.makeForm("shrubbery creation", "office");
		AForm* form2 = intern.makeForm("robotomy request", "Employee");
		AForm* form3 = intern.makeForm("presidential pardon", "Criminal");
		if (form1 && form2 && form3)
		{
			god.signForm(*form1);
			god.executeForm(*form1);
			
			std::cout << std::endl;
			god.signForm(*form2);
			god.executeForm(*form2);
			
			std::cout << std::endl;
			god.signForm(*form3);
			god.executeForm(*form3);
			
			delete (form1);
			delete (form2);
			delete (form3);
		}
	}
	std::cout << "\n=== Intern form with low grade bur ===\n" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("presidential pardon", "Prisoner");
		if (form)
		{
			Bureaucrat intern_bureaucrat("Intern", 150);
			std::cout << intern_bureaucrat << std::endl;
			intern_bureaucrat.signForm(*form);
			intern_bureaucrat.executeForm(*form);
			delete (form);
		}
	}
	
	return (0);
}
