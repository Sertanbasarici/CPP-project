#include "Span.hpp"

Span::Span(): N(0) {}

Span::Span(const unsigned int N)
{
    this->N = N;
}

Span::~Span() {}

Span::Span(const Span& original)
{
    for (size_t i = 0;i < original.N;i++)
        this->v.at(i) = original.v.at(i);
}

void    Span::addNumber(size_t num)
{
    if (this->v.size() < N)
        this->v.push_back(N);
    else
        throw outOfRange();
}

void    Span::multipleAddNumber(size_t num, const size_t times)
{
    for (size_t i = 0; i < times; i++)
    {
        if (this->v.size() < N)
            this->v.push_back(N);
        else
            throw outOfRange();
    }
}

