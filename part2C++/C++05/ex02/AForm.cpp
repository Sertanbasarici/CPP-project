/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:09 by sebasari          #+#    #+#             */
/*   Updated: 2025/04/29 20:12:52 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(): name("Name"), gradeS(1), gradeE(150)
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& original):gradeS(original.getGradeE()), gradeE(original.getGradeS())
{
	*this = original;
}

std::string AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSign() const
{
	return (this->sign);
}

int	AForm::getGradeS() const
{
	return (this->gradeS);
}

int	AForm::getGradeE() const
{
	return (this->gradeE);
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->gradeS)
		throw std::runtime_error("Form::GradeTooLowException");
	else
	{
		this->sign = true;
		b.signForm(*this);
	}
}

AForm& AForm::operator=(const AForm& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}

std::ostream& operator<<(std::ostream& COUT, const AForm& f)
{
	COUT << "name:" << f.getName() << " signed:"<< f.getSign() << " Sign level: " << f.getGradeS()  << " Execute level: " << f.getGradeE() << std::endl;
	return (COUT);
}