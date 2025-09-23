/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:10:29 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/10 20:58:44 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original): AForm(original)
{  
    *this = original;
}  

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw std::runtime_error("Forms are not signed...");
	else if (executor.getGrade() < 137)
	{
		std::fstream file1((this->target + "_shrubbery").c_str(), std::ios::out);  // Explicit open mode recommended
		if (file1.is_open())
		{
			file1 << "        *\n";
			file1 << "       ***\n";
			file1 << "      *****\n";
			file1 << "     *******\n";
			file1 << "    *********\n";
			file1 << "   ***********\n";
			file1 << "  *************\n";
			file1 << " ***************\n";
			file1 << "       |||\n";
			file1 << "       |||\n";
			file1.close();		std::fstream file1(this->target.c_str());

		}
		else
			file1.close();
	}
	else
		std::cout <<"Level does not match..."<< std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}