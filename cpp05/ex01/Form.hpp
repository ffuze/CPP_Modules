#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <stdbool.h>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int signingGrade;
		const int exGrade;
	public:
		Form();
		Form(const std::string name, bool sign, const int grade, const int exGrade);
		~Form();
		const std::string getName() const;
		const bool getSign() const;
		const int geSigningGrade() const;
		const int getExGrade() const;
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

std::ostream& operator<<(const std::ostream& os, const Form& obj);

#endif