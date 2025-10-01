#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

Intern::Intern() {}
Intern::Intern(const Intern& o){ (void)o;}
Intern::~Intern() {}
Intern& Intern::operator=(const Intern&){ return *this; }

static AForm* createShrub(const std::string& t){ return new ShrubberyCreationForm(t); }
static AForm* createRobot(const std::string& t){ return new RobotomyRequestForm(t); }
static AForm* createPardon(const std::string& t){ return new PresidentialPardonForm(t); }

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    const std::string keys[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm* (*creators[3])(const std::string&) = { &createShrub, &createRobot, &createPardon };

    if (target.empty())
        throw std::invalid_argument("Empty target.");
    for (int i=0;i<3;++i)
    {
        if (name == keys[i])
            {
            AForm* f = creators[i](target);
            std::cout << "Intern creates " << f->getName() << std::endl;
            return f;
        }
    }
    throw std::invalid_argument(std::string("Unknown Form type: ")+name);
}
