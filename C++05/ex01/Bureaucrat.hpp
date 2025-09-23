/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/04 18:13:15 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
class Form;

class Bureaucrat
{
protected:
	std::string	const	name;
	int					grade;
public:
	Bureaucrat();
	Bureaucrat(const int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& original);
public:
	std::string getName() const;
	int			getGrade() const;
	void		increamentGrade();
	void		decrementGrade();
	void		signForm(const Form& f);
public:
	Bureaucrat& operator=(const Bureaucrat& b);
};

class BureaucratExceptionHigh: public std::exception
{
public:
	explicit BureaucratExceptionHigh() {}
public:
	virtual const char* what() const throw()
	{
		return "Bureaucrat::GradeTooHighException";
	}
};

class BureaucratExceptionLow: public std::exception
{
public:
	explicit BureaucratExceptionLow() {}
public:
	virtual const char* what() const throw()
	{
		return "Bureaucrat::GradeTooLowException";
	}
};

std::ostream& operator<<(std::ostream &COUT, const Bureaucrat& b);
#endif