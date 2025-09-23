/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:16:19 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:28:00 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat( 1, "Daryl");
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		std::cout << "gecti"<< std::endl;
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception occured: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat(1, "Thomas");
		Intern someRandomIntern;
		AForm* Form;

		Form = someRandomIntern.makeForm("presidential pardoning", "White");
		bureaucrat.signForm(*Form);
		bureaucrat.executeForm(*Form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception occured: " << e.what() << std::endl;
	}

	return (0);
}