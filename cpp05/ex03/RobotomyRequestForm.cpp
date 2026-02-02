#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
        target = obj.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign())
        throw (std::runtime_error("the form must be signed to go on"));
    if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > this->getGradeToSign())
        throw (AForm::GradeTooLowException());
    std::cout << "* DRRRRRRR thank you for the protein sir DRRRRRRRRRRRRRRRRRRRRRR *" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}