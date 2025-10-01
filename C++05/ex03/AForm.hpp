/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:29:25 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 14:34:09 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool sign;
    const int gradeS;
    const int gradeE;

public:
    AForm();
    AForm(const std::string& name, int gradeS, int gradeE);
    AForm(const AForm& o);
    virtual ~AForm();
    AForm& operator=(const AForm& o);

    const std::string& getName() const;
    bool  getSign() const;
    int   getGradeS() const;
    int   getGradeE() const;

    void  beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const& executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        public: virtual ~GradeTooHighException() throw(){}
        virtual const char* what() const throw()
        {
            return "Form::GradeTooHighException";
        }
    };
    class GradeTooLowException  : public std::exception
    {
        public: virtual ~GradeTooLowException() throw(){}
            virtual const char* what() const throw()
            {
                return "Form::GradeTooLowException";
            }
    };
    class NotSignedException  : public std::exception
    {
        public: virtual ~NotSignedException() throw(){}
            virtual const char* what() const throw()
            {
                return "Form::NotSignedException";
            }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
