#include "Form.hpp"

Form::Form() : name("Default"), sign(false), gradeToSign(1), gradeToExecute(1)
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name(name), sign(sign), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
}

int Form::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() > this->getGradeToSign())
        throw (Form::GradeTooLowException());
    this->sign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade of the bureaucrat is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade of the bureaucrat is too low");
}

const std::string Form::getName() const
{
	return (name);
}

const bool Form::getSign() const
{
	return (sign);
}

const int Form::getGradeToSign() const
{
	return (gradeToSign);
}

const int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}
