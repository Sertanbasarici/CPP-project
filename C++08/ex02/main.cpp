#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    // normal stack gibi kullan
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // iterator kullanarak gezin
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "stack içeriği:" << std::endl;
    for (; it != ite; ++it)
        std::cout << *it << std::endl;

    return 0;
}
