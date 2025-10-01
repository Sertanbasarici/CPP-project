/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:29:50 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 13:53:56 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(int grade);
    Bureaucrat(const Bureaucrat& o);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& o);
public:
    const std::string& getName() const;
    int  getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& f) const;

    class GradeTooHighException : public std::exception
	{
    public: 
        virtual ~GradeTooHighException() throw()
		{
		}
        virtual const char* what() const throw()
		{
			return "Bureaucrat::GradeTooHighException";
		}
    };
    class GradeTooLowException : public std::exception
	{
    public:
        virtual ~GradeTooLowException() throw()
		{}
        virtual const char* what() const throw()
		{
			return "Bureaucrat::GradeTooLowException";
		}
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
