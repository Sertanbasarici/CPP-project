#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>  
#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <exception>
#include <string>


class outOfRange: public std::exception
{
public:
    explicit outOfRange() {}
public:
    virtual const char* what() const throw()
    {
        return "Exception: out of range";
    }
};

class Span
{
private:
    unsigned int N;
    std::vector<int> v;
public:
    Span();
    Span(const unsigned int N);
    ~Span();
    Span(const Span& original);
public:
    void        addNumber(const int  num);
    void        multipleAddNumber(const int num, const size_t times);
    unsigned int      shortestSpan();
    unsigned int      longestSpan();
    unsigned int      getN();
public:
    Span& operator=(const Span& other);

};

#endif