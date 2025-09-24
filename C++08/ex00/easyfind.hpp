#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>  
#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <exception>
#include <string>

class couldNotFindException:public std::exception
{
public:
    explicit couldNotFindException() {}
public:
    virtual const char* what() const throw()
    {
        return "Value not found:couldNotFindException";
    }
};

template <typename T>
typename T::const_iterator    easyfind(const T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw couldNotFindException();
    return (it);
}
#endif