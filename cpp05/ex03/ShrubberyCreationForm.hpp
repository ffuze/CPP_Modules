#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <stdbool.h>
# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
	public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
        void execute(Bureaucrat const & executor) const;
};

#endif