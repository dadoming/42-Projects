#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::endl;

void my_replace(string filename, string s1, string s2);


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[1] << " <filename> <str1> <str2>" << endl;
        return (1);    
    }
    my_replace(argv[1], argv[2], argv[3]);
    std::cout << "Replacement done" << endl;
    return (0);
}

void my_replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "Error opening input file" << endl;
        return ;
    }

    std::ofstream outfile(filename + ".replace");
    if (!outfile)
    {
        std::cerr << "Error opening output file" << endl;
        return ;
    }

    if (infile.is_open())
    {
        char            buffer;
        std::string     str;
        while (infile.get(buffer))
        {
            str += buffer;
        }

        int iter = str.find(s1);
        while (iter != std::string::npos)
        {
            str.erase(iter, s1.length());
            str.insert(iter, s2);
            iter = str.find(s1);
        }
        outfile << str;
    }

    infile.close();
    outfile.close();
}
