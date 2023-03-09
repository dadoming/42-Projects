# include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
    type = weapon_type;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}

const std::string& Weapon::getType(void)
{
    std::string const& weapon_name = type;
    return (weapon_name);
}

