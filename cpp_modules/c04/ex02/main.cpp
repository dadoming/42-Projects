# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
    Animal* a = Animal::create();
    a->makeSound();
    delete a;
    std::cout << std::endl;
    

    Animal const *b = new Dog();
    b->makeSound();
    delete b;

    // test
    // Animal *c = new Animal();
    return (0);
}