# ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{

public:

    HumanA(std::string human_name, Weapon& starter_weapon);
    ~HumanA();

    void attack( void );

private:

    std::string _name;
    Weapon&     _weapon;

};

# endif
