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
        std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << endl;
        return (1);    
    }
    my_replace(argv[1], argv[2], argv[3]);
    return (0);
}

void my_replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream infile(filename);
    if (!infile) { std::cerr << "Error opening input file" << endl; return ; }

    std::ofstream outfile(filename + ".replace");
    if (!outfile) { std::cerr << "Error opening output file" << endl; infile.close(); return ; }

    if (infile.is_open())
    {
        // copy file to string
        char            buffer;
        std::string     str;
        while (infile.get(buffer))
        {
            str += buffer;
        }

        // replace
        for(int i = str.find(s1); i != std::string::npos; i = str.find(s1))
        {
            str.erase(i, s1.length());
            str.insert(i, s2);
        }

        // write to file
        outfile << str;
    }

    infile.close();
    outfile.close();
}
