#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <iostream>
# include <stdlib.h>
# include <limits>
# include <float.h>
# include <string>
# include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);
    
public:
    ~ScalarConverter();
    
    static void convert(char *value);
};

#endif