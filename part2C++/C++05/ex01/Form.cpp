/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:09 by sebasari          #+#    #+#             */
/*   Updated: 2025/04/28 21:57:57 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): name("Name"), gradeS(1), gradeE(150)
{
}

Form::~Form()
{
}

Form::Form(const Form& original):gradeS(original.getGradeE()), gradeE(original.getGradeS())
{
	*this = original;
}

std::string Form::getName() const
{
	return (this->name);
}

bool	Form::getSign() const
{
	return (this->sign);
}

int	Form::getGradeS() const
{
	return (this->gradeS);
}

int	Form::getGradeE() const
{
	return (this->gradeE);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->gradeS)
		throw std::runtime_error("Form::GradeTooLowException");
	else
	{
		this->sign = true;
		b.signForm(*this);
	}
}

Form& Form::operator=(const Form& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}

std::ostream& operator<<(std::ostream& COUT, const Form& f)
{
	COUT << "name:" << f.getName() << " signed:"<< f.getSign() << " Sign level: " << f.getGradeS()  << " Execute level: " << f.getGradeE() << std::endl;
	return (COUT);
}