/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:03:45 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/13 11:43:08 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mainheader.hpp"

bool	IsAlphaForString(std::string string)
{
	for (size_t i = 0; i < string.length();i++)
		if (!(std::isalpha(string[i])))
			return (false);
	return (true);
}

bool	IsAlnumForString(std::string string)
{
	for (size_t i = 0; i < string.length();i++)
		if (!(std::isalnum(string[i])))
			return (false);
	return (true);
}

bool	IsdigitForString(std::string string)
{
	for (size_t i = 0; i < string.length();i++)
		if (!(std::isdigit(string[i])))
			return (false);
	return (true);
}

int main()
{
	std::string	command;
	PhoneBook	myPhoneBook;

	myPhoneBook.setIndex(0);
	while (true)
	{
		std::cout << "Please enter a command (ADD, SEARCH or EXIT):";;
		getline(std::cin, command);
		if (command == "ADD")
			myPhoneBook.AddPhonebook();
		else if (command == "SEARCH")
			myPhoneBook.SearchInPhoneBook(myPhoneBook);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid entry please enter a valid command!!!" << std::endl;
	}
	std::cout << "The program was safely turned off" << std::endl;
	return (0);
}
