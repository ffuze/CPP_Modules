#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::cout << "complain(\"DEBUG\"):" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "complain(\"INFO\"):" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "complain(\"WARNING\"):" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "complain(\"ERROR\"):" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "complain(\"debug\"):" << std::endl;
    harl.complain("debug");
    std::cout << std::endl;

    std::cout << "complain(\"INVALID\"):" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;

    std::cout << "complain(\"\"):" << std::endl;
    harl.complain("");
    std::cout << std::endl;

    std::cout << "complain(\"   \"):" << std::endl;
    harl.complain("");
    std::cout << std::endl;

    return 0;
}