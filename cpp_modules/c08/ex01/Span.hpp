#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <algorithm>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
private:
    Span();
    std::vector<int> _storage;
    unsigned int _max_value;

public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span &other);

    void addNumber(long int num);
    void fillWithRandomNumbers(unsigned int N);
    int shortestSpan() const;
    int longestSpan() const;
    void print() const;

    class SpanIsFullException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class OutOfBoundsValueException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class NoSpanException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif