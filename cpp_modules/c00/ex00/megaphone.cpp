# include <iostream>
# include <cctype>
# include <cstring>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            int len = strlen(argv[i]);
            for (int j = 0; j < len; j++)
            {
                argv[i][j] = std::toupper(argv[i][j]);
            }
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
    }
    else 
        std::cout << "HOW DO YOU USE A MEGAPHONE WITH NO WORDS?!"<< std::endl;
	
    return 0;
}
