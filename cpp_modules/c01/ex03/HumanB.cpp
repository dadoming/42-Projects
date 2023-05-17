# include "HumanB.hpp"

HumanB::HumanB(std::string human_name)
{
    _name = human_name;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& new_weapon)
{
    _weapon = &new_weapon;
}

void HumanB::attack( void )
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
