/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:12 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 14:08:14 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "\n=== Form invalid grades ===\n";
        try { Form bad1("Bad1", 0, 10); }    catch(const std::exception& e){ std::cout << e.what() << std::endl; }
        try { Form bad2("Bad2", 10, 151); }  catch(const std::exception& e){ std::cout << e.what() << std::endl; }

        std::cout << "\n=== beSigned success/fail ===\n";
        Bureaucrat bob("Bob", 100);
        Bureaucrat alice("Alice", 50);
        Form f("F", 75, 50);
        std::cout << f << std::endl;
        try { f.beSigned(bob); }   catch(const std::exception& e){ std::cout << "bob can't sign: " << e.what() << std::endl; }
        try { f.beSigned(alice); } catch(const std::exception& e){ std::cout << "alice can't sign: " << e.what() << std::endl; }
        std::cout << f << std::endl;

        std::cout << "\n=== Bureaucrat::signForm messages ===\n";
        Form g("G", 30, 30);
        Bureaucrat c("C", 40);
        Bureaucrat d("D", 10);
        c.signForm(g);
        d.signForm(g);
        std::cout << g << std::endl;
    } catch (...) {
        std::cout << "Unexpected top-level exception\n";
    }
}
