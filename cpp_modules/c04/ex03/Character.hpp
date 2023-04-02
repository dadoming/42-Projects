# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ClearMateria.hpp"

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip( AMateria* materia ) = 0;
    virtual void unequip( int idx ) = 0;
    virtual void use( int idx, ICharacter& target ) = 0;
};


class Character : public ICharacter
{
private:
    std::string  _name;
    AMateria     *_inventory[4];

public:
    Character();
    Character( const std::string &name );
    Character( const Character &copy );
    Character &operator=( const Character &copy );
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip( AMateria* materia );
    virtual void unequip( int idx );
    virtual void use( int idx, ICharacter& target );
};

# endif
