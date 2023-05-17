#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon& starter_weapon) : _weapon(starter_weapon)
{
    _name = human_name;
}

HumanA::~HumanA()
{
}

void HumanA::attack( void )
{
    if (_weapon.getType() != "")
    {
        std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
    }
}
