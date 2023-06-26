#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <string>
# include <exception>
# include <cstdlib>
# include <limits>
# include <time.h>

#define YELLOW "\033[0;33m"
#define RED	"\033[0;31m"
#define RESET "\033[0m"
#define THRESHOLD 10

class PMergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deque;

    long _timeStartVec;
    long _timeStartDeque;
    long _timeEndVec;
    long _timeEndDeque;

public:
    PMergeMe();
    PMergeMe(const PMergeMe &other);
    PMergeMe &operator=(const PMergeMe &other);
    ~PMergeMe();

    void loadContainers(char **argv);
    void printContainers(std::string message);
    void sortContainers();

    std::vector<int> getVec();
    std::deque<int> getDeque();

    class BadInputException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

template <typename T> void printContainer(T &container, std::string cont_name);
template <typename T> void mergeInsertionSort(T& A, int start, int end);

#endif