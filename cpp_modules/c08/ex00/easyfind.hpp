# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

class ValueNotInContainer : public std::exception
{
    public:
        const char *what() const throw() { return ("CAUGHT EXCEPTION: Value was not found inside container"); }
};

template <typename T>
typename T::iterator easyfind(T& container, int x)
{
    typename T::iterator found = std::find(container.begin(), container.end(), x);
    if (found == container.end())
        throw ValueNotInContainer();
    return found;
}

#endif