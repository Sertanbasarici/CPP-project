#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Name"), grade(150) {}
Bureaucrat::Bureaucrat(const std::string& n) : name(n), grade(150) {}
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
Bureaucrat::Bureaucrat(const Bureaucrat& o) : name(o.name), grade(o.grade) {}
Bureaucrat::~Bureaucrat()
{}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& o)
{
    if(this!=&o)
        grade=o.grade;
    return *this;
}

const std::string& Bureaucrat::getName() const { return name; }
int  Bureaucrat::getGrade() const { return grade; }
void Bureaucrat::incrementGrade()
{
    if (grade<=1)
        throw GradeTooHighException();
    --grade;
}
void Bureaucrat::decrementGrade()
{
    if (grade>=150)
        throw GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(AForm& f) const
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
void Bureaucrat::executeForm(AForm const& f) const
{
    try
    {
        f.execute(*this); std::cout << name << " executed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    return os<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<".";
}
