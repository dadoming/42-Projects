# include <iostream>

int main()
{
    str[] = "Hello World";
    //int len = strlen(str);
    //std::cout << "String length: " << len << std::endl;
    
    std::cout << "Testing Lengths:" << std::endl;
    int len = std::char_traits<char>::length(str);
    std::cout << len << std::endl;

    std::cout << "Atoi in character:" << std::endl;
    int c = std::char_traits<char>::to_int_type('1');
    std::cout << c << std::endl;

    std::cout << "Testing assign in char:" << std::endl;
    char a = 'a';
    char b = 'b';
    std::char_traits<char>::assign(a, b);
    std::cout << "a= " << a << std::endl << "b= " << b << std::endl;
    std::cout << "address 'a': " << &a << std::endl << "address 'b': " << &b << std::endl;
    
    std::cout << "Testing assign in string:" << std::endl;
    //char str[] = "Hello World";
    //char em = '!';
    std::char_traits<char>::assign(str, len + 10, '\0');
    std::cout << "String changed: " << str << std::endl;

    return (0);  
}