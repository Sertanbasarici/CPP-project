#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form",145,137), target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t) : AForm("Shrubbery Creation Form",145,137), target(t) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o) : AForm(o), target(o.target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{
    if(this!=&o)
    {
        AForm::operator=(o); target=o.target;
    } 
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!getSign())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeE()) 
        throw AForm::GradeTooLowException();
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
    {
        std::cout << "Failed to open output file\n"; return;
    }
    file << "        *\n"
         << "       ***\n"
         << "      *****\n"
         << "     *******\n"
         << "    *********\n"
         << "   ***********\n"
         << "  *************\n"
         << " ***************\n"
         << "       |||\n"
         << "       |||\n";
}
