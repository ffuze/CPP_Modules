#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <stdbool.h>
# include <ostream>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		~Form();
		std::string getName() const;
		bool getSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bur);
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif