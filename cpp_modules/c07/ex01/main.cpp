# include "iter.hpp"

#define INT_ARRAY_LEN 6
#define STR_ARRAY_LEN 3

int main( void )
{
    int int_array[INT_ARRAY_LEN];
    int int_array_len = INT_ARRAY_LEN;
    while (int_array_len--)
        int_array[int_array_len] = int_array_len;
    
    ::iter(int_array, INT_ARRAY_LEN, print);
    std::cout << std::endl;

    std::string str_array[STR_ARRAY_LEN];
    int str_array_len = STR_ARRAY_LEN;
    while (str_array_len--)
        str_array[str_array_len] = "lol" + std::string(1, str_array_len + '0');

    ::iter(str_array, STR_ARRAY_LEN, print);

    return 0;
}
