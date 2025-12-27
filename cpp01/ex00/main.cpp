#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Alek");
    zombie->announce();
    delete (zombie);
}