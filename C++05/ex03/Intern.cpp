/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:50:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:03:58 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& original)
{
	*this = original;
}

AForm* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &FormName, const std::string &FormTarget)
{
	const std::string FormTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*FormCreators[3])(const std::string &) = {&createShrubbery, &createRobotomy, &createPresidentialPardon};
	
	for (int i = 0; i < 3; i++)
		if (FormName == FormTypes[i] && !FormTarget.empty())
			return FormCreators[i](FormTarget);
	if (FormTarget.empty())
		throw std::invalid_argument("Empty target.");
	throw std::invalid_argument("Unknown Form type: " + FormName);
}

Intern& Intern::operator=(const Intern& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}