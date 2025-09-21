#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}

template <typename T>
void increment(T &x)
{
     x++;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    double darr[3] = {1.1,2.2,3.3};
    char carr[6] = {'h','e','l','l','o','\0'};
    std::string sarr[3] = {"hello", "c++", "templates"};

    std::cout << "Int: ";
    iter(arr, 5, print<int>); std::cout << "\n";
    iter(arr, 5, increment<int>);
    iter(arr, 5, print<int>); std::cout << "\n\n";

    std::cout << "Double: ";
    iter(darr, 3, print<double>); std::cout << "\n";
    iter(darr, 3, increment<double>);
    iter(darr, 3, print<double>); std::cout << "\n\n";

    std::cout << "Char: " << carr << "\n";
    iter(carr, 5, increment<char>);
    std::cout << carr << "\n\n";

    std::cout << "String: ";
    iter(sarr, 3, print<std::string>);
    std::cout << "\n";

    return 0;
}
