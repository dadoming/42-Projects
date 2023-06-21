#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include "Array.hpp"

template< typename T >
void iter( T* array, size_t array_len, void (*f)(T &))
{
    for (size_t i = 0; i < array_len; i++)
    {
        f(array[i]);
    }
}

template<typename T>
void iter(Array<T> &array, size_t array_len, void (*f)(T &))
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

template <typename T>
void add1(T &i)
{
    i += 1;
}

#endif