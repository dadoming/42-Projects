#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>      // std::istringstream
# include <map>
# include <limits>
# include <cstdlib>

class BitcoinExchange
{

private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

public:
    static void exchange(const char* filename);

    class NotPositiveException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    
    class BadInputException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class NumberTooBigException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

#endif