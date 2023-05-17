# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{

public:

    Weapon(std::string weapon_type);
    ~Weapon();

    void  setType(std::string new_type);
    const std::string& getType(void);

private:
    
    std::string _type;

};

# endif
