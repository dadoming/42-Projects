# ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "Character.hpp"
# include "ClearMateria.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria( const std::string &type );
    AMateria( const AMateria &copy );
    AMateria &operator=( const AMateria &copy );
    virtual ~AMateria();

    const std::string& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use( ICharacter& target );
};

# endif