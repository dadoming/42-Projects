# include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
    _type = weapon_type;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string new_type)
{
    _type = new_type;
}

const std::string& Weapon::getType(void)
{
    std::string const& weapon_name = _type;
    return (weapon_name);
}

