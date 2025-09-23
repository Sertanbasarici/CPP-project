/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:17 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:26:47 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Default")
{
}

Bureaucrat::Bureaucrat(const int grade, std::string name1): name(name1)
{
	if (grade < 1)
		throw BureaucratExceptionHigh();
	else if (grade > 150)
		throw BureaucratExceptionLow();
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
		throw BureaucratExceptionHigh();
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw BureaucratExceptionLow();
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

void	Bureaucrat::signForm(AForm& f) const
{
		f.beSigned(*this);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
		*this = b;
	return *this;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "error: "<< e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& b)
{
	COUT << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
	return COUT;
}