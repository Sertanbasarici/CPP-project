#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& o);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& o);

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
