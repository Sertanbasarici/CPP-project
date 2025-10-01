/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:30:11 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 14:05:06 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Name"), grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& n) : name(n), grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g)
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(int g) : name("Name"), grade(g)
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& o):name(o.name), grade(o.grade)
{
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& o)
{
    if (this!=&o)
        grade=o.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int  Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}
void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(Form& f) const
{
    try 
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
