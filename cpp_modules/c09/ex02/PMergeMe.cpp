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
        _vec = other._vec;
        _deque = other._deque;
        _timeStartVec = other._timeStartVec;
        _timeStartDeque = other._timeStartDeque;
        _timeEndVec = other._timeEndVec;
        _timeEndDeque = other._timeEndDeque;
    }
    return *this;
}

template <typename T> static void insertionSort(T& container, int start, int middle) 
{
    for (int i = start; i <= middle; i++) 
    {
        int temp = container[i];
        int j = i;
        while (j > start && container[j - 1] > temp) {
            container[j] = container[j - 1];
            j--;
        }
        container[j] = temp;
    }
}

template <typename T> static void merge(T& container, int start, int middle, int end) {
    int n1 = middle - start + 1;
    int n2 = end - middle;
    T leftIter(container.begin() + start, container.begin() + middle + 1);
    T rightIter(container.begin() + middle + 1, container.begin() + end + 1);
    int rightIndex = 0;
    int leftIndex = 0;
    for (int i = start; i <= end; i++) 
    {
        if (rightIndex == n2) 
        {
            container[i] = leftIter[leftIndex];
            leftIndex++;
        } 
        else if (leftIndex == n1) 
        {
            container[i] = rightIter[rightIndex];
            rightIndex++;
        } 
        else if (rightIter[rightIndex] > leftIter[leftIndex]) 
        {
            container[i] = leftIter[leftIndex];
            leftIndex++;
        } 
        else 
        {
            container[i] = rightIter[rightIndex];
            rightIndex++;
        }
    }
}

template <typename T> void mergeInsertionSort(T& container, int start, int end) 
{
    if (end - start > THRESHOLD) 
    {
        int middle = (start + end) / 2;
        mergeInsertionSort(container, start, middle);
        mergeInsertionSort(container, middle + 1, end);
        merge(container, start, middle, end);
    } 
    else
        insertionSort(container, start, end);
}

void PMergeMe::sortContainers()
{
    _timeStartVec = clock();
    mergeInsertionSort(_vec, 0, _vec.size() - 1);
    _timeEndVec = clock() - _timeStartVec;
    _timeStartDeque = clock();
    mergeInsertionSort(_deque, 0, _deque.size() - 1);
    _timeEndDeque = clock() - _timeStartDeque;
}

template <typename T> void printContainer(T &container, std::string cont_name)
{
    typename T::iterator it = container.begin();
    std::cout << YELLOW << cont_name << RESET;
    while (it != container.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void PMergeMe::printContainers(std::string message)
{
    if (message == "Before:")
    {
        std::cout << RED << message << RESET << std::endl;
        printContainer(_vec, "Vector : ");
        printContainer(_deque, "Deque  : ");
    }
    else if (message == "After:")
    {
        std::cout << RED << message << RESET << std::endl;
        printContainer(_vec, "Vector : ");
        printContainer(_deque, "Deque  : ");
        std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector :  ";
        std::cout << static_cast<float>(_timeEndVec) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
        std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  :  ";
        std::cout << static_cast<float>(_timeEndDeque) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
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
                _deque.push_back(argv[i][0] - '0');
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
                        _deque.push_back(num);
                        num = 0;
                        j++;
                    }
                    else if (argv[i][j] == '\0')
                    {
                        _vec.push_back(num);
                        _deque.push_back(num);
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

std::deque<int> PMergeMe::getDeque()
{
    return _deque;
}

const char *PMergeMe::BadInputException::what() const throw()
{
    return ("Error");
}