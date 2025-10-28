#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, int length, void (*f)(T &))
{
    if (!array) return;
    for (int i = 0; i < length; ++i)
        f(array[i]);
}

template <typename T>
void iter(T const *array, int length, void (*f)(T const &))
{
    if (!array) return;
    for (int i = 0; i < length; ++i)
        f(array[i]);
}


#endif