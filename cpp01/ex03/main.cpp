#include "HumanB.hpp"

int main(void)
{
    Weapon club = Weapon("");
    HumanB jim("Jim");
    // jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
}