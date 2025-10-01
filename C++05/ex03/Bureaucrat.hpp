#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(int grade);
    Bureaucrat(const Bureaucrat& o);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& o);

    const std::string& getName() const;
    int  getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& f) const;
    void executeForm(AForm const& f) const;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual ~GradeTooHighException() throw() {}
            virtual const char* what() const throw()
            {
                return "Bureaucrat::GradeTooHighException";
            }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual ~GradeTooLowException() throw() {}
            virtual const char* what() const throw()
            {
                return "Bureaucrat::GradeTooLowException";
            }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
