/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:57:52 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/30 10:59:46 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <cstdlib>

# include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void increaseGrade();
        void decreaseGrade();
        void signForm(Form& form);
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
