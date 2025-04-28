#include <iostream>

class custom_exception: public std::exception
{
	virtual const char* what() const noexcept
	{
		return "Custom exception";
	}
};

int main()
{

	std::string word;

	word = "four";

	
	try
	{
		//std::cout <<word.at(4)<< std::endl;
		//int *array = new int[99999999999999];
		throw std::runtime_error("agaa");
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: "<< e.what()<< std::endl;
	}
}