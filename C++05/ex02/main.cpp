#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void checkFile(const std::string& path){
    std::ifstream f(path.c_str());
    std::cout << "Check file '" << path << "': " << (f ? "OK" : "MISSING") << std::endl;
}

int main(){
    std::srand(std::time(0));
    try{
        std::cout << "\n=== Shrubbery ===\n";
        ShrubberyCreationForm sh("home");     // sign 145, exec 137
        Bureaucrat sLow("sLow", 146);         // imza yetersiz
        Bureaucrat sOk ("sOk", 145);          // imza tam sınır
        Bureaucrat eLow("eLow", 140);         // exec yetersiz
        Bureaucrat eOk ("eOk", 130);          // exec yeterli

       // try { sh.beSigned(sLow); } catch(const std::exception& e){ std::cout << e.what() << std::endl; }
        sh.beSigned(sOk);
        sOk.signForm(sh);
        // try { sh.execute(eLow); } catch(const std::exception& e){ std::cout << e.what() << std::endl; }
        eOk.executeForm(sh);                   // veya: sh.execute(eOk);
        checkFile("home_shrubbery");

        std::cout << "\n=== Robotomy (random) ===\n";
        RobotomyRequestForm rb("Bender");     // sign 72, exec 45
        Bureaucrat rbSign( "rbSign", 72);
        Bureaucrat rbExecL("rbExecL", 46);
        Bureaucrat rbExecO("rbExecO", 45);
        rb.beSigned(rbSign);
        try { rb.execute(rbExecL); } catch(const std::exception& e){ std::cout << e.what() << std::endl; }
        rbExecO.executeForm(rb);
        rbExecO.executeForm(rb);              // bir kaç kez çağırıp %50 başarıyı gözle

        std::cout << "\n=== Presidential ===\n";
        PresidentialPardonForm pp("Arthur Dent"); // sign 25, exec 5
        Bureaucrat pSign("pSign", 25);
        Bureaucrat pExecL("pExecL", 6);
        Bureaucrat pExecO("pExecO", 5);
        pp.beSigned(pSign);
        try { pp.execute(pExecL); } catch(const std::exception& e){ std::cout << e.what() << std::endl; }
        pExecO.executeForm(pp);

        std::cout << "\n=== Execute without signing ===\n";
        ShrubberyCreationForm sh2("yard");
        try { eOk.executeForm(sh2); } catch(const std::exception& e){ std::cout << e.what() << std::endl; }
    } catch(...) {
        std::cout << "Unexpected top-level exception\n";
    }
}
