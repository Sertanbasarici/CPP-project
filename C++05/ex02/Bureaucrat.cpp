/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:17 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/10 20:50:32 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Name")
{
}

Bureaucrat::Bureaucrat(const int grade): name("Name")
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

void	Bureaucrat::signForm(const AForm& f) const
{
	if (this->grade < f.getGradeE())
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	else if (this->grade > f.getGradeE())
		std::cout << this->name << " could not execute because "<< f.getName() <<"'s execution level does not match" << std::endl;
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
		std::cerr << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& b)
{
	COUT << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
	return COUT;
}