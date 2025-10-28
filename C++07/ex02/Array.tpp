#include "Array.hpp"


template <typename T>
Array<T>::Array(): data(NULL), size_(0)
{

}

template <typename T>
Array<T>::~Array()
{
    delete [] data;
}

template <typename T>
Array<T>::Array(unsigned int n): data(NULL), size_(n)
{
    if (size_ > 0)
    {
        data = new T[n]();
    }
}

template <typename T>
Array<T>::Array(const Array& array): data(NULL), size_(array.size_)
{
    if (size_ > 0)
    {
        this->data = new T[array.size_]();
        for (unsigned int i = 0;i < array.size_;i++)
            this->data[i] = array.data[i];
    }
}

template<typename T>
unsigned int Array<T>::size() const
{
    return this->size_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        T* newData = (other.size_ > 0) ? new T[other.size_] : NULL;
        try
        {
            for (unsigned int i = 0; i < other.size_; ++i)
                newData[i] = other.data[i];
        } catch (...)
        {
            delete[] newData;
            throw;
        }
        delete[] data;

        this->data = newData;
        this->size_ = other.size_;
    }
    return *this;
}

template <typename T>
T&  Array<T>::operator[](unsigned int index)
{
    if (this->size_ > index)
        return this->data[index];
    else
        throw std::out_of_range("Array: out of range");
}

template <typename T>
const T&  Array<T>::operator[](unsigned int index) const
{
    if (this->size_ > index)
        return this->data[index];
    else
        throw std::out_of_range("Array: out of range");
}