#include "MutantStack.hpp"
#include <list>
#include "iostream"

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl << "-----------" << std::endl << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        mstack.push(906);
        mstack.push(198);
        mstack.push(9);
        mstack.push(8);
        mstack.push(3);
        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            it++;
        }
    }
    return 0;
}