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
    MutantStack():stack() {};
    ~MutantStack() {};

};

#endif
