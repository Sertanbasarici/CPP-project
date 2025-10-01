#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& o);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& o);

    virtual void execute(Bureaucrat const& executor) const;
};

#endif
