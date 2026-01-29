/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:58:22 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/26 19:34:27 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

const std::string Bureaucrat::getName() const
{
	return (name);
}

void Bureaucrat::decreaseGrade()
{
	if (grade + 1 > 150)
		throw (GradeTooLowException());
	this->grade++;
}

void Bureaucrat::increaseGrade()
{
	if (grade - 1 < 1)
		throw (GradeTooHighException());
	this->grade--;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade of bureaucrat too high (max is 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade of bureaucrat too low (min is 150)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}