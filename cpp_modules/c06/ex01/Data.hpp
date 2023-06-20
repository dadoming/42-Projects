#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
private:
    std::string _s1;
    int _n;
    std::string _s2;

public:
    Data();
    ~Data();
    Data(const Data& other);
    Data& operator=(const Data& other);

    std::string getS1() const;
    void setS1(std::string s1);
    int getN() const;
    void setN(int n);
    std::string getS2() const;
    void setS2(std::string s2);
};

#endif