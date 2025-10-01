#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), sign(false), gradeS(150), gradeE(150) {}
AForm::AForm(const std::string& n, int s, int e) : name(n), sign(false), gradeS(s), gradeE(e)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS > 150 || gradeE > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& o) : name(o.name), sign(o.sign), gradeS(o.gradeS), gradeE(o.gradeE) {}
AForm::~AForm() {}
AForm& AForm::operator=(const AForm& o)
{
    if(this!=&o)
        sign=o.sign;
    return *this; }

const std::string& AForm::getName() const { return name; }
bool  AForm::getSign() const { return sign; }
int   AForm::getGradeS() const { return gradeS; }
int   AForm::getGradeE() const { return gradeE; }

void  AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeS)
        throw GradeTooLowException();
    sign = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os<< "Form Name: " << f.getName() << "\n"
      << "Grade required to sign: " << f.getGradeS() << "\n"
      << "Grade required to execute: " << f.getGradeE() << "\n"
      << "Signed: " << (f.getSign() ? "True" : "False");
    return os;
}
