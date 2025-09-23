/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:09 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:27:26 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(): name("AForm"), gradeS(150), gradeE(150)
{
}

AForm::AForm(std::string name1, int gradeS1, int gradeE1): name(name1), gradeS(gradeS1), gradeE(gradeE1)
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

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->gradeS)
		throw FormExceptionLow();
	else
	{
		this->sign = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

AForm& AForm::operator=(const AForm& f)
{
	if (this != &f)
		*this = f;
	return (*this);
}