#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& o);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& o);

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
