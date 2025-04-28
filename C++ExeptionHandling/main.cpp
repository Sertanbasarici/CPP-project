#include <iostream>

void	stdException(std::string str)
{
	try
	{
		std::cout << str.at(str.size() + 1)<< std::endl;
		
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::runtime_error& e1)
	{
		std::cout << "Exception runtime_error: " << e1.what() << std::endl;
	}
}

int main()
{
	stdException("ahmet");
}