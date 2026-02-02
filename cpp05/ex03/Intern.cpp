#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& obj)
{
    (void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
    (void)obj;
    return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    std::string lowerFormName = formName;
    for (size_t i = 0; i < lowerFormName.length(); i++)
        lowerFormName[i] = std::tolower(lowerFormName[i]);
    for (int i = 0; i < 3; i++)
    {
        if (lowerFormName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i)
            {
            case 0:
                return new ShrubberyCreationForm(formTarget);
                break;
            case 1:
                return new RobotomyRequestForm(formTarget);
                break;
            case 2:
                return new PresidentialPardonForm(formTarget);
                break;
            default:
                break;
            }
        }
    }
    std::cout << "FORM NAME \"" << formName << "\" DOESNT EXISTS LOL" << std::endl;
    return (NULL);
}
