# include "Base.hpp"

/*
dynamic_cast <new_type>(expression)

0. dynamic_cast is used at run time to find out correct down-cast.
1: Need at least one virtual function in base class.
2: If the cast is successful, dynamic_cast returns a value of type new_type. 
3: If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
4: If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast

*/
int main( void )
{
    Base *base = generate();

    std::cout << "base = " << base << std::endl;
    
    identify(base);
    identify(*base);

    delete base;
    return (0);
}