# include "AMateria.hpp"

AMateria::AMateria() : _type(nullptr) {}

AMateria::AMateria( const std::string &type ) : _type(type) {}

AMateria::AMateria( const AMateria& other ) { *this = other; }

AMateria &AMateria::operator=( const AMateria& other )
{
    this->_type = other._type;
    return (*this);
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const { return (_type); }

void AMateria::use(ICharacter& target)
{
    if (_type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (_type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    else
        std::cout << "AMateria::use() called" << std::endl;
}
