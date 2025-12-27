#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1 || name.empty())
        return (NULL);
    Zombie* zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombie[i].nameZombie(name);
    }
    return (zombie);
}
