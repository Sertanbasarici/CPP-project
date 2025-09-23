/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:24:17 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string	const	name;
	bool				sign;
	int const			gradeS;
	int const			gradeE;
public:
	AForm();
	AForm(std::string name1, int gradeS1, int gradeE1);
	virtual ~AForm() = 0;
	AForm(const AForm& original);
public:
	std::string		getName() const;
	bool			getSign() const;
	int				getGradeS() const;
	int				getGradeE() const;
	void			beSigned(const Bureaucrat& b);
	virtual void			execute(Bureaucrat const &executor) const = 0;
public:
	AForm& operator=(const AForm& f);
};

class FormExceptionHigh: public std::exception
{
public:
	explicit FormExceptionHigh() {}
public:
	virtual const char* what() const throw()
	{
		return "Form::GradeTooHighException";
	}
};

class FormExceptionLow: public std::exception
{
public:
	explicit FormExceptionLow() {}
public:
	virtual const char* what() const throw()
	{
		return "Bureaucrat::GradeTooLowException";
	}
};

#endif