#include "AForm.hpp"

AForm::AForm() : name("Default"), sign(false), gradeToSign(1), gradeToExecute(1)
{
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() > this->getGradeToSign())
        throw (AForm::GradeTooLowException());
    this->sign = true;
}

AForm::GradeTooHighException::GradeTooHighException()
{
}

AForm::GradeTooLowException::GradeTooLowException()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade of the bureaucrat is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade of the bureaucrat is too low");
}

std::string AForm::getName() const
{
	return (name);
}

bool AForm::getSign() const
{
	return (sign);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}
