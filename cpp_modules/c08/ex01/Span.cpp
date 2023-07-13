#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _max_value(N)
{
    _storage.reserve(N);
}

Span::~Span() {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_max_value = other._max_value;
        this->_storage = other._storage;
    }
    return (*this);
}

const char* Span::SpanIsFullException::what() const throw()
{
    return ("CAUGHT EXCEPTION: trying to add number to already full Span");
}

const char* Span::OutOfBoundsValueException::what() const throw()
{
    return ("CAUGHT EXCEPTION: trying to add number outside INT values");
}

const char* Span::NoSpanException::what() const throw()
{
    return ("CAUGHT EXCEPTION: there are not enough numbers to calculate span");
}

void Span::addNumber(long int num)
{
    try
    {
        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
            throw OutOfBoundsValueException();
        if (_storage.size() >= _max_value)
            throw SpanIsFullException();
        _storage.push_back(num);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int randomNum () { return (std::rand() % 100000); }

void Span::fillWithRandomNumbers(unsigned int N)
{
    try
    {
        if (N > _max_value)
            throw (std::length_error("CAUGHT EXCEPTION: trying to fill Span with more numbers than its capacity"));
        
        if (_storage.size() + N > _max_value)
            throw SpanIsFullException();
        std::srand(std::time(0));
        for (unsigned int i = 0; i < N; ++i) 
        {
            _storage.push_back(randomNum());
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Span::fillWithSequentialNumbers(unsigned int N)
{
    try
    {
        if (N > _max_value)
            throw (std::length_error("CAUGHT EXCEPTION: trying to fill Span with more numbers than its capacity"));
        
        if (_storage.size() + N > _max_value)
            throw SpanIsFullException();
        
        for (unsigned int i = 0; i < N; ++i)
        {
            _storage.push_back(i);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

int Span::shortestSpan() const
{
    try
    {
        if (_storage.size() < 2)
            throw NoSpanException();
        
        std::vector<int> copy = _storage;
        std::sort(copy.begin(), copy.end());
        std::vector<int>::iterator it = copy.begin();
        int min = *(it + 1) - *it;
        for (; it != copy.end() - 1; it++)
        {
            if (*(it + 1) - *it < min)
                min = *(it + 1) - *it;
        }
        return (min);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

int Span::longestSpan() const
{
    try
    {
        if (_storage.size() < 2)
            throw NoSpanException();
        
        std::vector<int>::const_iterator smallest = std::min_element(_storage.begin(), _storage.end());
        std::vector<int>::const_iterator biggest = std::max_element(_storage.begin(), _storage.end());
        return (*biggest - *smallest);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

void Span::print() const
{
    std::vector<int>::const_iterator it = _storage.begin();
    for (; it != _storage.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
