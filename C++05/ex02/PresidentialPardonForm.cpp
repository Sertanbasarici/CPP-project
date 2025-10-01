#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form",25,5), target("default") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& t) : AForm("Presidential Pardon Form",25,5), target(t) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o) : AForm(o), target(o.target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o)
{
    if(this!=&o)
    {
        AForm::operator=(o);
        this->target=o.target;
    }
        return *this; 
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!getSign())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeE())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned\n";
}
