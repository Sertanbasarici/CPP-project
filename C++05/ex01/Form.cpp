/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:52:27 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 13:59:31 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), sign(false), gradeS(150), gradeE(150)
{
}
Form::Form(const std::string& n, int s, int e) : name(n), sign(false), gradeS(s), gradeE(e)
{
    if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
    if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& o) : name(o.name), sign(o.sign), gradeS(o.gradeS), gradeE(o.gradeE)
{}
Form::~Form()
{}
Form& Form::operator=(const Form& o)
{
	if(this!=&o)
		sign=o.sign;
	return *this;
}

const std::string& Form::getName() const
{
	return name;
}
bool  Form::getSign() const
{
	return sign;
}
int   Form::getGradeS() const
{
	return gradeS;
}
int   Form::getGradeE() const 
{
	return gradeE;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeS)
		throw GradeTooLowException();
    sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form Name: " << f.getName() << "\n"
       << "Grade required to sign: " << f.getGradeS() << "\n"
       << "Grade required to execute: " << f.getGradeE() << "\n"
       << "Signed: " << (f.getSign() ? "True" : "False");
    return os;
}
