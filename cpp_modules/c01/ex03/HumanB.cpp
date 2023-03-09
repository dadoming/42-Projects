# include "HumanB.hpp"

HumanB::HumanB(std::string human_name)
{
    name = human_name;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& new_weapon)
{
    weapon = &new_weapon;
}

void HumanB::attack( void )
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
