#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::announce()
{
    std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::nameZombie(std::string name)
{
    Zombie::_name = name;
}

Zombie::~Zombie()
{
    std::cout << Zombie::_name << " was caught lackin'..." << std::endl;
}