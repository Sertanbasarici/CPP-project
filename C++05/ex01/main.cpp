/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:12 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/04 18:31:59 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat b(2);
	Form a;
	try 
	{
		Bureaucrat ba(15);
		
		ba.increamentGrade();
		ba.increamentGrade();
		a.beSigned(ba);
		//std::cout << ba << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	//std::cout << a << std::endl;
}