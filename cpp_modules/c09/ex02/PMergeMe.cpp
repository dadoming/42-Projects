#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::~PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe &other)
{
    *this = other;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other)
{
    if (this != &other)
    {
        
    }
    return *this;
}

void PMergeMe::sortContainers()
{
    _timeStartVec = clock();
    std::sort(_vec.begin(), _vec.end());
    _timeEndVec = clock() - _timeStartVec;
    _timeStartList = clock();
    _list.sort();
    _timeEndList = clock() - _timeStartList;
}

void PMergeMe::printContainers(std::string message)
{
    std::cout << message << "\t";
    size_t i = 0;
    while (i < _vec.size())
    {
        std::cout << _vec[i] << " ";
        i++;
    }
    std::cout << std::endl;
    if (message == "After:")
    {
        std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector :  " << static_cast<float>(_timeEndVec) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
        std::cout << "Time to process a range of " << _list.size() << " elements with std::list   :  " << static_cast<float>(_timeEndList) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
    }
}

void PMergeMe::loadContainers(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        std::string str = std::string(argv[i]);
        int len = str.length();
        if (len == 1)
        {
            if (argv[i][0] >= '0' && argv[i][0] <= '9')
            {
                _vec.push_back(argv[i][0] - '0');
                _list.push_back(argv[i][0] - '0');
            }
            else
                throw BadInputException();
        }
        else if (len > 1) 
        {
            int j = 0;
            int num = 0;
            while (argv[i][j])
            {
                if (argv[i][j] >= '0' && argv[i][j] <= '9')
                {
                    num = num * 10 + (argv[i][j] - '0');
                    if (num > std::numeric_limits<int>::max() || num < 0) 
                        throw BadInputException();
                    j++;
                    if (isspace(argv[i][j]))
                    {
                        _vec.push_back(num);
                        _list.push_back(num);
                        num = 0;
                        j++;
                    }
                    else if (argv[i][j] == '\0')
                    {
                        _vec.push_back(num);
                        _list.push_back(num);
                    }
                }
                else
                    throw BadInputException();
            }
        }
        else
            throw BadInputException();
        i++;
    }
}

std::vector<int> PMergeMe::getVec()
{
    return _vec;
}

std::list<int> PMergeMe::getList()
{
    return _list;
}

const char *PMergeMe::BadInputException::what() const throw()
{
    return ("Error");
}