#include "MutantStack.hpp"
#include <list>

int main(void)
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        //std::cout << mstack.top() << std::endl;
        mstack.pop();
        //std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        lst.pop_back();
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        //[...]
        lst.push_back(0);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        std::cout << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(lst);
    }
    return 0;
}