#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
    this->operator=(obj);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
        this->target = obj.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!this->getSign())
        throw (std::runtime_error("The form must be signed to go on"));
    if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > this->getGradeToSign())
        throw (AForm::GradeTooLowException());
    std::cout << "THE COURT MASTER ZAPHOD BEEBLEBROX HAS DECIDED TO APPROVE THE PARDON TO " << target << std::endl;
}