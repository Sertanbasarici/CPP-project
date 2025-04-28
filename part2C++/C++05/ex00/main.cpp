/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:12 by sebasari          #+#    #+#             */
/*   Updated: 2025/03/19 12:49:41 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b(2);
	try 
	{
		Bureaucrat ba(2);
		ba.increamentGrade();
		ba.increamentGrade();
		std::cout << ba << std::endl;
		std::cout << ba.getName() << std::endl;
		std::cout << ba.getGrade() << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	// std::cout << b << std::endl;
}