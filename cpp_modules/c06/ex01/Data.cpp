# include "Data.hpp"

Data::Data()
{
}

Data::~Data()
{
}

Data::Data(const Data& other)
{
    (void)other;
}

Data& Data::operator=(const Data& other)
{
    (void)other;
    return *this;
}

std::string Data::getS1() const
{
    return _s1;
}

void Data::setS1(std::string s1)
{
    _s1 = s1;
}

int Data::getN() const
{
    return _n;
}

void Data::setN(int n)
{
    _n = n;
}

std::string Data::getS2() const
{
    return _s2;
}

void Data::setS2(std::string s2)
{
    _s2 = s2;
}
