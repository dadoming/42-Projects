#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <string>
# include <exception>
# include <cstdlib>
# include <limits>
# include <time.h>


class PMergeMe
{
private:
    std::vector<int> _vec;
    std::list<int> _list;

    long _timeStartVec;
    long _timeStartList;
    long _timeEndVec;
    long _timeEndList;

public:
    PMergeMe();
    PMergeMe(const PMergeMe &other);
    PMergeMe &operator=(const PMergeMe &other);
    ~PMergeMe();

    void loadContainers(char **argv);
    void printContainers(std::string message);
    void sortContainers();

    std::vector<int> getVec();
    std::list<int> getList();

    class BadInputException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};


#endif