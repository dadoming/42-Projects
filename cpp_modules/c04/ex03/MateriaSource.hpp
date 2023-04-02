# ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource();
    virtual void learnMateria( AMateria* materia) = 0;
    virtual AMateria* createMateria( const std::string& type ) = 0;
};


class MateriaSource : public IMateriaSource
{
private:
    AMateria *_inventory[4];

public:
    MateriaSource();
    MateriaSource( const MateriaSource &other );
    MateriaSource &operator=( const MateriaSource &other );
    virtual ~MateriaSource();

    virtual void learnMateria( AMateria* materia );
    virtual AMateria* createMateria( const std::string& type );
};

# endif
