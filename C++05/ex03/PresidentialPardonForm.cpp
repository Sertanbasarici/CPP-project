/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:23:40 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/10 21:29:08 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original): AForm(original)
{
	*this = original;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5)
{
	this->target = target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw std::runtime_error("Forms are not signed...");
	else if (executor.getGrade() < 5)
	{
		std::cout << this->target << " has been pardoned" << std::endl;
	}
	else
		throw std::runtime_error("Levels are not match...");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}