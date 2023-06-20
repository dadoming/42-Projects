#include "Base.hpp"

Base::~Base()
{
}

Base * generate(void)
{
    srand(time(NULL));
    int r = rand() % 3;
    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class type: C" << std::endl;
    else 
        std::cout << "Class type: Unknown" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Class type: A" << std::endl;
        (void)a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " -> Not class A" << std::endl;
    }

    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Class type: B" << std::endl;
        (void)b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " -> Not class B" << std::endl;
    }

    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Class type: C" << std::endl;
        (void)c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " -> Not class C" << std::endl;
    }
    
}
