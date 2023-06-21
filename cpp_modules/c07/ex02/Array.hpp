#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{

private:
    T*      _array;
    int     _len;

public:
    Array();
    Array(unsigned int n);
    Array(Array const& other);
    T& operator=(Array const& other);
    T& operator[](unsigned int i);
    ~Array();
    int size() const;

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw(); 
    };

};

template <typename T>
Array<T>::Array()
{
    this->_array = new T[0];
    this->_len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n];
    _len = n;
}

template <typename T>
Array<T>::Array(Array const& other)
{
    this->_array = new T[other._len];
    this->_len = other._len;
    for (int i = 0; i < _len; i++)
        this->_array[i] = other._array[i];
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (static_cast<int>(i) >= this->_len)
        throw OutOfBoundsException();
    return this->_array[i];
}

template <typename T>
T& Array<T>::operator=(Array const& other)
{
    if (this != &other)
    {
        delete [] this->_array;
        this->_array = new T[other._len];
        this->_len = other._len;
        for (int i = 0; i < other->_len; i++)
            this->_array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "Index out of bounds";
}

template <typename T>
int Array<T>::size() const { return this->_len; }

template <typename T>
Array<T>::~Array()
{
    delete [] this->_array;
}

#endif