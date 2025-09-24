#include "easyfind.hpp"


template <typename T>
void    assignNumber(T &array,int length)
{
    for (int i = 0;i < length;i++)
        array.push_back(i);
}

int main()
{
    std::vector<int> v1;
    std::vector<std::string> v2;
    std::vector<int>::const_iterator it_v; 
    
    assignNumber(v1, 15);
    v2.push_back("ahmet");
    v2.push_back("memo");
    v2.push_back("cabir");
    v2.push_back("hasan");
    try
    {
        it_v = easyfind(v1, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(1);
    }
    std::cout <<"vector" << *it_v << std::endl;

    std::list<int> l1;
    std::list<std::string> l2;
    std::list<int>::const_iterator it_l; 
    assignNumber(l1, 15);
    l2.push_back("ahmet");
    l2.push_back("memo");
    l2.push_back("cabir");
    l2.push_back("hasan");
    try
    {
        it_l = easyfind(l1, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(1);
    }
    std::cout <<"list:" << *it_l << std::endl;
}