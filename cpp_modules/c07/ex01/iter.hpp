#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T >
void iter( T* array, size_t array_len, void (*f)(T &))
{
    for (size_t i = 0; i < array_len; i++)
    {
        f(array[i]);
    }
}

template <typename T>
void print(T &i)
{
    std::cout << i << std::endl;
}

#endif