#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(){
         std::srand(std::time(0));
        Intern intern;
        Bureaucrat boss("Boss", 1);
//
        //std::cout << "\n=== Valid names ===\n";
        //const char* names[]   = {"shrubbery creation", "robotomy request", "presidential pardon"};
        //const char* targets[] = {"home", "Bender", "Arthur Dent"};
//
        //for (int i = 0; i < 3; ++i){
        //    try {
        //        AForm* f = intern.makeForm(names[i], targets[i]);
        //        if (!f)
        //        {
        //            std::cout << "makeForm returned NULL for '" << names[i] << "'\n";
        //            continue;
        //        }
        //        boss.signForm(*f);
        //        boss.executeForm(*f);
        //        std::cout << *f << std::endl;
        //        delete f;
        //    } catch (const std::exception& e) {
        //        std::cout << "Error for '" << names[i] << "': " << e.what() << std::endl;
        //    }
        //}

        std::cout << "\n=== Invalid name ===\n";
        try
        {
            AForm* bad = intern.makeForm("coffee request", "me");
            if (bad) { std::cout << "Unexpectedly created: " << *bad << std::endl; delete bad; }
        } catch (const std::exception& e){
            std::cout << "Expected error: " << e.what() << std::endl;
        }
}
