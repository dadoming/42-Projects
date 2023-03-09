#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon& starter_weapon) : weapon(starter_weapon)
{
    name = human_name;
}

HumanA::~HumanA()
{
}

void HumanA::attack( void )
{
    if (weapon.getType() != "")
    {
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    }
}
