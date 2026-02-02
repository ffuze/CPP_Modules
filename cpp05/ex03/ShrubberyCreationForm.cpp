#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
    this->operator=(obj);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
        target = obj.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign())
        throw (std::runtime_error("the form must be signed to go on"));
    if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > this->getGradeToSign())
        throw (AForm::GradeTooLowException());
    std::string tree[] = {
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣀⡀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⢀⢀⠠⢄⠀⠀⠘⠀⠠⠼⡀⠠⠤⣀⣀⣾⣷⡾⣿⣷⣀⢳⣿⣿⣿⣦⣆⡠⢀⣀⡸⠄⢀⠘⠤⢄⠀⠤⢄⢀⠀⠀⠀⠡⠜⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⢠⠀⠀⢠⣿⣏⠱⢾⡙⢏⠟⡥⢩⠛⣼⠷⢫⡹⡿⢟⢿⣛⡿⣿⣷⣦⣠⣤⡄⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀",
        "⠀⠀⠰⠀⢰⠒⠁⠈⠒⣶⣬⣶⣟⠻⡹⢾⣿⠻⠍⠆⠈⠄⡀⢩⢆⠙⡀⠇⣉⢾⡾⣵⣾⣿⣯⢿⣟⣿⣿⣶⠐⠁⠐⠒⠁⠈⠀⠀⠀",
        "⠀⠀⢀⠀⢀⠀⢂⣰⣟⠏⡿⣿⣟⣳⣕⣻⣦⢋⡔⠀⠁⠠⠐⠈⡌⠀⢠⠐⣊⠲⣱⢻⡾⣽⣻⢿⣾⢟⣿⣿⣿⣤⣄⡀⠆⠸⠀⠀⠀",
        "⠀⠀⠈⠀⢰⣤⣶⣿⣯⣞⣽⣿⣛⢶⡺⣧⢆⣡⡀⠄⡁⠐⠤⢁⠢⢡⠄⣒⠦⢳⡡⣏⡖⢧⢫⢏⡜⣯⣿⣻⣽⢻⣿⣧⣄⣀⠀⠀⠀",
        "⠀⠠⢰⣶⠾⡟⡧⣿⢿⡿⣿⣽⣛⣶⣽⣯⣛⠤⣐⠈⡄⢩⠐⢂⡱⣠⢛⡴⢩⠳⣝⣭⢻⣭⡷⣎⣽⣽⣻⣷⢾⣩⣖⣿⡿⠋⠀⠀⠀",
        "⠀⠀⢀⣻⢮⡱⢻⣿⢯⣿⡙⡷⢻⡙⣾⣳⡿⣏⡙⣎⡐⡡⡜⢆⢧⡱⢎⠾⣥⢻⡼⣾⠻⡅⡛⡗⣿⢾⣻⣿⣟⣶⣿⣻⣷⡶⠀⠀⠀",
        "⠀⠨⢙⣿⣯⣷⡿⢇⠲⡅⠹⢈⠡⢏⡔⢫⣟⣾⣝⣦⣳⡱⣭⣞⢦⣝⢮⣻⡜⣧⣟⡹⠅⢀⠡⢙⠴⡻⢭⢓⡎⠗⣮⠿⣿⣦⡀⠀⠀",
        "⠀⢠⢭⡹⠬⣙⢳⡉⠂⢀⠐⠠⠑⡄⢬⢲⣹⣿⣿⣿⣷⣿⣷⣿⣷⣿⣿⣷⣹⣶⢏⡒⠀⠂⢀⠁⢊⠘⣇⠎⠘⡠⠃⡞⡥⠾⣧⡄⠀",
        "⢀⡸⡑⠆⠡⠐⢨⠚⠄⣀⠂⡅⢣⠼⣭⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⠀⢂⠀⠎⢠⠑⡈⠀⢂⠠⠑⠠⠜⡓⣎⣳⡦",
        "⡨⢒⠠⠀⡐⠈⡀⡘⠰⣠⢓⣬⢳⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣡⡐⠆⡨⠘⡀⠆⢀⠐⠀⡂⢌⡡⢆⣹⠴⣻⠀",
        "⠁⣇⠒⡁⠄⡠⢡⢈⣅⠲⣭⢾⣿⣿⣿⣿⣿⣿⣿⣿⡯⠿⢿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣽⣡⡗⣱⡜⡰⢂⠠⡑⡌⢀⡳⢍⣦⢻⣏⠁",
        "⠀⠗⣏⢄⢣⡔⣢⠝⣆⠷⣮⣷⣿⣿⣿⣿⣿⡿⠟⢿⣿⣶⣼⣿⡿⣧⣿⣿⠾⠛⢛⣿⣿⣿⣿⣿⣼⠱⣊⠶⡱⣍⢦⠹⣜⡸⢿⣅⠀",
        "⠀⢀⠙⠘⡯⣶⣿⣞⣿⣿⣾⣿⣿⣿⣿⣿⠛⣟⣆⠀⠙⣿⣿⣿⣿⣿⣿⠃⡆⠀⠀⣿⣿⣿⣿⣿⣷⣯⢧⣓⡳⡜⡶⣫⢼⣹⡧⠛⠁",
        "⠀⠀⠁⠀⠐⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠿⣿⣿⣆⠀⢸⣿⣿⣿⣿⡿⠀⠀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣧⣿⣵⣫⡵⠯⠾⠽⠃⠀⠀",
        "⠀⠈⠈⠀⠸⠤⡀⠻⠿⠛⢙⠟⠟⠁⠧⠔⠀⠠⠍⠛⢿⣿⣿⣿⣿⣿⣇⣴⣾⣿⠟⢋⠉⠻⢿⣿⣿⣿⣿⡿⠿⡀⠠⠤⡀⢀⠀⠀⠀",
        "⠀⢀⠠⠀⢠⠀⠀⠘⠀⠀⠘⠀⠀⠀⡄⢀⠀⠄⠠⠁⠂⠹⣿⣿⣿⣿⣿⣿⠛⠀⠀⠜⠀⠀⠈⠀⠈⢈⠀⢠⠀⠁⠠⠀⠀⠘⠀⠀⠀",
        "⠀⠈⠀⠒⠂⠈⠒⢲⠀⠐⠲⠁⠐⠒⠁⠀⠒⠀⠈⠒⠎⠈⣿⣿⣿⣿⡟⠁⠐⠒⠀⢱⠒⠀⠰⠒⠊⠀⠒⠊⠈⠒⠂⠀⠖⢲⠀⠀⠀",
        "⠀⠐⠀⢀⡰⠀⢀⣀⠀⢀⣀⠄⢀⣀⠆⠐⢀⠀⠐⣀⡀⠀⣿⣿⣿⣿⣻⠀⠆⣀⠀⢀⣀⠀⢀⣀⡀⠀⠀⡐⠀⢀⡀⠀⣀⣀⠀⠀⠀",
        "⠀⢀⢀⠤⢄⠀⠄⠘⠀⠀⠌⡀⠀⠠⡀⢀⠠⠀⢀⠤⠀⠀⣿⣿⣿⣿⣿⠀⡀⠀⠀⡸⠀⠀⠈⠤⠀⢀⠀⢄⢀⠂⠄⠀⠁⠜⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠄⢠⠀⠀⢠⠂⠀⠀⠃⠀⠀⠀⠀⠀⡄⠀⣿⣿⣿⣿⣿⡀⠃⠀⠀⢠⠀⠀⢠⠀⠄⠀⠀⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀",
        "⠀⢐⠰⠁⢐⠒⠀⠀⠂⠀⠈⠂⠀⠈⡆⠰⠀⠒⠐⠁⢐⢒⣿⣿⣿⣿⣿⡇⡎⠀⠂⡊⠀⠀⠂⠀⠑⠐⠁⢰⠐⠁⠐⠂⠀⠈⠀⠀⠀",
        "⠀⠀⢀⠀⢀⢀⠀⠸⠀⠀⠸⠀⠀⠀⡀⠀⠀⡀⢀⠂⠆⣸⣿⣿⣿⣿⣿⡇⡀⠀⡀⠸⠀⠀⢈⠀⠁⢀⠀⢀⢀⠃⢀⠀⠅⠸⠀⠀⠀",
        "⠀⠈⠀⠀⠘⠀⠀⢀⠀⠀⢠⠂⠀⠀⠃⠈⠀⠀⠐⠀⠀⣾⣿⣿⣿⣿⣿⣿⣀⠀⠀⢡⠀⠀⢀⠀⡀⠈⠀⠈⠀⡀⠀⠀⡀⢠⠀⠀⠀",
        "⠀⠠⢀⠒⢢⠀⠐⠊⠀⠐⠊⠄⠐⠒⡄⣀⣂⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣬⣒⡀⠈⠒⠀⠀⠐⢢⠀⠑⠂⠀⠑⠈⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠐⠀⠀⠀⠁⠈⢀⠈⠉⡉⠍⠉⡏⠉⠉⠉⠉⠉⢉⠉⠀⢰⠁⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠐⠀⠀"
    };
    std::string ibuffer;
    if (target.empty())
    {
        std::cout << "A name for the file is needed!" << std::endl;
        return;
    }
    std::ofstream newFile((std::string(target + "_shrubbery")).c_str());
    if (!newFile.is_open())
    {
        std::cout << "New file cannot be created" << std::endl;
		return;
    }
    for (int i = 0; i < 27; i++)
    {
        newFile << tree[i] << std::endl;
    }
}