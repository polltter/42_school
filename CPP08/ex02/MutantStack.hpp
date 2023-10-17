//
// Created by miguel on 17-10-2023.
//

#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP
#include "stack"
#include "vector"
template<class T>
class MutantStack: public  std::stack<T> {
public:
    MutantStack() {}
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    iterator begin()
    {
        return (this->c.begin());
    }
    iterator end()
    {
        return (this->c.end());
    }
    reverse_iterator rbegin()
    {
        return (this->c.rbegin());
    }
    reverse_iterator rend()
    {
        return (this->c.rend());
    }
    const_iterator cbegin()
    {
        return (this->c.cbegin());
    }
    const_iterator cend()
    {
        return (this->c.cend());
    }
    iterator crbegin()
    {
        return (this->c.crbegin());
    }
    iterator crend()
    {
        return (this->c.crend());
    }


};

#endif //CPP08_MUTANTSTACK_HPP
