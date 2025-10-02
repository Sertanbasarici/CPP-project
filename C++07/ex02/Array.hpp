#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstdlib>

template <typename T> 
class Array
{
private:
    T* data;
    unsigned int size_;
public:
    Array();
    ~Array();
    Array(unsigned int n);
    Array(const Array& array);
public:
    unsigned int size() const;
public:
    Array<T>& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
};


#include "Array.tpp"
#endif