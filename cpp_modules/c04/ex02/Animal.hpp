# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

public:

    virtual ~Animal();

    virtual void  makeSound() const = 0;
    virtual void  spitIdea(int i) const = 0;
    std::string   getType() const;

protected:
    Animal();
    Animal &operator=( const Animal &copy );
    Animal( const Animal &copy );

    std::string _type;

};

# endif
