/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:23:58 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/10 21:27:57 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b(11);
	ShrubberyCreationForm f1("well");
	RobotomyRequestForm f2("Gizli");
	PresidentialPardonForm f3("acik");

	// f1.beSigned(b);
	// f2.beSigned(b);
	f3.beSigned(b);
	// b.executeForm(f1);
	// b.executeForm(f2);
	b.executeForm(f3);
}