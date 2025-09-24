#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &f, T &s)
{
    T tmp;
    tmp = f;
    f = s;
    s = tmp;
}
template <typename T>
T min(const T &f,const T &s)
{
    return (f < s ? f : s);
}
template <typename T>
T max(const T &f,const T &s)
{
    return (f > s ? f : s);
}

#endif