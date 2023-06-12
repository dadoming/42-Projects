# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

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