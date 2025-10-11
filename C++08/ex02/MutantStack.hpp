#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>
#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <exception>
#include <string>


template <typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack(){};
    ~MutantStack() {};
    MutantStack(const MutantStack& other): std::stack<T>(other){};
    MutantStack &operator=(const MutantStack& other) 
    {
        std::stack<T>::operator=(other);
        return *this;
    };
public:

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }

};

#endif
