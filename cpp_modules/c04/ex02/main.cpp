# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"


// Because the class Animal has all the constructors inside the protected section,
// we can't create an instance of it. We can only create instances of its derived classes 
// ( cats and dogs ).

int main( void )
{
    //Animal a;

    //Animal *a = new Animal();
    
    std::cout << std::endl;
    
    Animal const *b = new Dog();
    b->makeSound();
    delete b;

    return (0);
}