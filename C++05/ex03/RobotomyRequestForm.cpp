#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form",72,45), target("default") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& t) : AForm("Robotomy Request Form",72,45), target(t) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o) : AForm(o), target(o.target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o)
{
    if(this!=&o)
    {
        AForm::operator=(o);
        target=o.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getSign())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeE())
        throw AForm::GradeTooLowException();
    std::cout << "BZZZZT\n";
    if (std::rand() % 2)
        std::cout << target << " has been robotomized\n";
    else
        std::cout << "Robotomy failed on " << target << "\n";
}
