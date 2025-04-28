/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:17 by sebasari          #+#    #+#             */
/*   Updated: 2025/04/28 18:20:36 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Name")
{
}

Bureaucrat::Bureaucrat(const int grade): name("Name")
{
	if (grade < 1)
		throw std::runtime_error("Bureaucrat::GradeTooHighException");
	else if (grade > 150)
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original)
{
	*this = original;
}
Bureaucrat::~Bureaucrat()
{
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::increamentGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw std::runtime_error("Bureaucrat::GradeTooHighException");
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw std::runtime_error("Bureaucrat::GradeTooLowException");
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
		*this = b;
	return *this;
}

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& b)
{
	COUT << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
	return COUT;
}