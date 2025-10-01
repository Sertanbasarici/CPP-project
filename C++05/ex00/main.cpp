/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:12 by sebasari          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:47 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void line(const std::string& t){ std::cout << "\n=== " << t << " ===\n"; }

int main()
{
    try
	{
        line("Valid extremes");
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);
        std::cout << top << std::endl;
        std::cout << bottom << std::endl;

        line("Invalid construction");
        try { Bureaucrat tooHigh("X", 0); }   catch (const std::exception& e){ std::cout << e.what() << std::endl; }
        try { Bureaucrat tooLow ("Y", 151);}  catch (const std::exception& e){ std::cout << e.what() << std::endl; }

        line("Increment boundary");
        Bureaucrat a("A", 2);
        std::cout << a << std::endl;
        a.incrementGrade(); // -> 1
        std::cout << a << std::endl;
        try { a.incrementGrade(); } catch(const std::exception& e){ std::cout << "inc beyond 1 -> " << e.what() << std::endl; }

        line("Decrement boundary");
        Bureaucrat b("B", 149);
        std::cout << b << std::endl;
        b.decrementGrade(); // -> 150
        std::cout << b << std::endl;
        try { b.decrementGrade(); } catch(const std::exception& e){ std::cout << "dec beyond 150 -> " << e.what() << std::endl; }
    } catch (...) {
        std::cout << "Unexpected top-level exception\n";
    }
}
