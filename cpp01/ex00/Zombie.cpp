#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

void Zombie::announce()
{
    std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << Zombie::_name << " was caught lackin'..." << std::endl;
}