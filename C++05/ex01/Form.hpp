/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/04 19:33:15 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string	const	name;
	bool				sign;
	int const			gradeS;
	int const			gradeE;
public:
	Form();
	~Form();
	Form(const Form& original);
public:
	std::string		getName() const;
	bool			getSign() const;
	int				getGradeS() const;
	int				getGradeE() const;
	void			beSigned(Bureaucrat& b);
public:
	Form& operator=(const Form& f);
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

std::ostream& operator<<(std::ostream& COUT, const Form& b);
#endif