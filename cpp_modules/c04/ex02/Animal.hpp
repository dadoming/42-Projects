# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

public:
    static Animal* create();

    virtual ~Animal();

    virtual void  makeSound() const;
    virtual void  spitIdea(int i) const;
    std::string   getType() const;

protected:
    Animal();
    Animal &operator=( const Animal &copy );
    Animal( const Animal &copy );

    std::string _type;

};

# endif
