/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:59:18 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:31:18 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original): AForm(original)
{
	*this = original;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45)
{
	this->target = target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw std::runtime_error("Forms are not signed...");
	else if (executor.getGrade() < 45)
	{
		std::cout << "BZZZZT"<< std::endl;
		std::srand(std::time(0));
		if (std::rand() % 2 == 0)
			std::cout << this->target << " has been robotomized" << std::endl;
		else
			std::cout << this->target << " has been failed to robotomized" << std::endl;
	}
	else
		std::cout <<"Level does not match..."<< std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}