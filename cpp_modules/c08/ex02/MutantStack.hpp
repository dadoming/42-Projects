#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {};
    MutantStack(const MutantStack& other) {*this = other;}
    MutantStack& operator=(const MutantStack& other) {
        std::stack<T>::operator=(other);
        return (*this);
    }
    ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;

    typename std::stack<T>::container_type::iterator begin() {
        return (std::stack<T>::c.begin());
    }

    typename std::stack<T>::container_type::iterator end() {
        return (std::stack<T>::c.end());
    }

};

/*

    By default, std::stack uses std::deque as the underlying container type. 
        The container is accessible through the 'c' member of std::stack, 
        which represents the underlying container.

*/

#endif