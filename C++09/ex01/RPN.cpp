#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &cpy)
{
    if (this != &cpy)
    {
        this->stack = cpy.stack;
    }
}

RPN &RPN::operator=(const RPN &copy)
{
    (void)copy;
    return *this;
}

int RPN::calculate(char c)
{
    if (stack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    int b = stack.top();  
    stack.pop();
    int a = stack.top();  
    stack.pop();

    if (c == '+')
        stack.push(a + b);

    else if (c == '-')
        stack.push(a - b);

    else if (c == '*')
        stack.push(a * b);

    else if (c == '/')
    {
        if (b == 0)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        stack.push(a / b);
    }

    else
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}

void RPN::executer(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if (c == ' ')
            continue;
        else if (c >= '0' && c <= '9')
        {
            stack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (calculate(c))
                return;
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << stack.top() << std::endl;
}
