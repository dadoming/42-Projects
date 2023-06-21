# include "easyfind.hpp"

int main(void)
{
    try
    {
        std::vector<int> vec;

        for(int i = 0; i < 5; i++)
            vec.push_back(i);
        std::cout << "Size of the vector: " << vec.size() << std::endl;
        std::vector<int>::iterator value = ::easyfind(vec, 2);
        for(;value != vec.end(); ++value )
            std::cout << *value << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::list<int> lst;
        
        for (int i = 0; i < 5; i++)
            lst.push_back(i);

        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
            std::cout << *it << std::endl;

        std::cout << std::endl;

        for(std::list<int>::iterator it = ::easyfind(lst, 6); it != lst.end(); ++it)
            std::cout << *it << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}