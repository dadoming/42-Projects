# include "ScalarConverter.hpp"

static void printChar(std::string const &value, char *end, long double num);
static void printInt(std::string const &value, char *end, long double num);
static void printFloat(std::string const &value, char *end, float f);
static void printDouble(std::string const &value, char *end, long double num);

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    *this = other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(char *value)
{
    char *end;
    std::string str = value;
    long double num = strtod(value, &end);
    float f = static_cast<float>(num);
    //std::cout << "num: " << num << std::endl;
    //std::cout << "end: " << *end << std::endl;
    //std::cout << "end_length: " << static_cast<std::string>(end).length() << std::endl;
    printChar(str, end, num);
    printInt(str, end, num);
    printFloat(str, end, f);
    printDouble(str, end, num);
}

/*
    The C library function double strtod(const char *str, char **endptr) 
        converts the string pointed to by the argument str to a floating-point 
        number (type double). If endptr is not NULL, a pointer to the character 
        after the last character used in the conversion is stored in the location 
        referenced by endptr.
*/

static void printChar(std::string const &value, char *end, long double num)
{
    std::cout << "char: ";
    size_t end_length = static_cast<std::string>(end).length();
    if ((end_length == value.length()) || \
        (end_length > 1) || \
        (end_length == 1 && *end != 'f'))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (num < 0 || num > 127 || value == "-inff" || value == "+inff" || \
        value == "nanf" || value == "-inf" || value == "+inf" || value == "nan")
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (num >= 32 && num <= 126)
        std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

static void printInt(std::string const &value, char *end, long double num)
{
    std::cout << "int: ";
    size_t end_length = static_cast<std::string>(end).length();
    if ((end_length == value.length()) || \
        (end_length > 1) || \
        (end_length == 1 && *end != 'f') || \
        (value == "-inff" || value == "+inff" || value == "nanf" || \
        value == "-inf" || value == "+inf" || value == "nan"))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (num > std::numeric_limits<int>::max() || \
        num < std::numeric_limits<int>::min())
    {
        std::cout << "overflow" << std::endl;
        return;
    }
    std::cout << static_cast<int>(num) << std::endl;
}

static void printFloat(std::string const &value, char *end, float f)
{
    std::cout << "float: ";
    size_t end_length = static_cast<std::string>(end).length();
    if ((value != "-inff" || value != "+inff" || value != "nanf" || \
        value != "-inf" || value != "+inf" || value != "nan") && \
        ((end_length == value.length()) || \
        (end_length > 1) || \
        (end_length == 1 && *end != 'f')))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (value == "-inff" || value == "nanf" || value == "-inf" || value == "nan")
        std::cout << f;
    else if (value == "+inf" || value == "+inff" || value == "inf" || value == "inff")
        std::cout << "+" << f;
    else if (f + 0.00000001 > std::numeric_limits<float>::max() || \
            f + 0.00000001 < std::numeric_limits<float>::min())
    {
        std::cout << "overflow" << std::endl;
        return;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1) << f;
    }
    std::cout << "f" << std::endl;
}

static void printDouble(std::string const &value, char *end, long double num)
{
    std::cout << "double: ";
    size_t end_length = static_cast<std::string>(end).length();
    if ((value != "-inff" || value != "+inff" || value != "nanf" || \
        value != "-inf" || value != "+inf" || value != "nan") && \
        ((end_length == value.length()) || \
        (end_length > 1) || \
        (end_length == 1 && *end != 'f')))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (value == "-inff" || value == "nanf" || value == "-inf" || value == "nan")
        std::cout << num;
    else if (value == "+inf" || value == "+inff" || value == "inf" || value == "inff")
        std::cout << "+" << num;
    else if (num + 0.00000001 > std::numeric_limits<double>::max() || \
            num + 0.00000001 < std::numeric_limits<double>::min())
    {
        std::cout << "overflow" << std::endl;
        return;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(num);
    }
    std::cout << std::endl;
}
