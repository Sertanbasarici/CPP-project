#include "Span.hpp"

Span::Span(): N(0) {}

Span::Span(const unsigned int N)
{
    this->N = N;
}

Span::~Span() {}

Span::Span(const Span& original): N(original.N), v(original.v) {}

void    Span::addNumber(int num)
{
    if (this->v.size() < N)
        this->v.push_back(num);
    else
        throw outOfRange();
}

void    Span::multipleAddNumber(int num, const size_t times)
{
    for (size_t i = 0; i < times; i++)
    {
        if (this->v.size() < N)
            this->v.push_back(num);
        else
            throw outOfRange();
    }
}

unsigned int Span::longestSpan()
{
    if (this->v.size() < 2)
        throw outOfRange();
    std::vector<int>::const_iterator min = std::min_element(this->v.begin(), this->v.end());
    std::vector<int>::const_iterator max = std::max_element(this->v.begin(), this->v.end());
    long long longest = static_cast<long long>(*max) - static_cast<long long>(*min);
    
    return static_cast<unsigned int>(longest); 
}

unsigned int Span::shortestSpan()
{
    if (this->v.size() < 2)
        throw outOfRange();
    std::vector<int> tmp = this->v;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator iterator;
    long long diff = 4294967295;
    for (iterator = tmp.begin(); iterator + 1 != tmp.end();iterator++)
    {
        if (*(iterator + 1) - *(iterator) < diff)
            diff = static_cast<long long>(*(iterator + 1)) - static_cast<long long>(*(iterator));
    }
    return diff;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->v = other.v;
    }
    return *this;
}

unsigned int Span::getN()
{
    return this->N;
}