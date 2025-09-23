/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:17 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/04 18:32:59 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	Bureaucrat::signForm(const Form& f)
{
	if (f.getGradeE() > this->grade)
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	else if (f.getGradeE() < this->grade)
		std::cout << this->name << " could not execute because "<< f.getName() <<"'s execution level does not match" << std::endl;
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