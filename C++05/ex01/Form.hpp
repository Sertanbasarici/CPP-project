/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 13:57:06 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool sign;
    const int gradeS;
    const int gradeE;

public:
    Form();
    Form(const std::string& name, int gradeS, int gradeE);
    Form(const Form& o);
    ~Form();
    Form& operator=(const Form& o);

    const std::string& getName() const;
    bool  getSign() const;
    int   getGradeS() const;
    int   getGradeE() const;

    void  beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception
	{
    	public: virtual ~GradeTooHighException() throw()
		{
		}
		virtual const char* what() const throw()
		{
			return "Form::GradeTooHighException";
		}
    };
    class GradeTooLowException  : public std::exception
	{
    	public: virtual ~GradeTooLowException() throw()
		{}
		virtual const char* what() const throw()
		{
			return "Form::GradeTooLowException";
		}
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
