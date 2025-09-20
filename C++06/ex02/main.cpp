#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// 0..RAND_MAX arası sayı üretir
static int myRandRange(int min, int max)
{
    return min + (std::rand() % (max - min + 1));
}

Base* generate(void)
{
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }

    int r = myRandRange(1, 3);
    if (r == 1)
        return new A();
    else if (r == 2)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (!p)
    {
        std::cerr << "error: empty pointer\n";
        return;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p); 
        std::cout << "A\n";
        return;
    } 
    catch (...)
    {}
    try
    { 
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (...)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (...)
    {}
    std::cout << "Unknown\n";
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        Base* obj = generate();

        std::cout << "identify(Base*): ";
        identify(obj);

        std::cout << "identify(Base&): ";
        identify(*obj);

        delete obj;
        std::cout << "------" << std::endl;
    }
    return 0;
}
