/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:35:44 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/13 12:03:17 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mainheader.hpp"

void	Contact::EnterContacts()
{
	std::string	buffer;
	std::cout << "Please enter the first name:";
	getline(std::cin, buffer);
	if (IsAlphaForString(buffer))
		setFirstName(buffer);
	std::cout << "Please enter the last name:";
	getline(std::cin, buffer);
	if (IsAlphaForString(buffer))
		setLastName(buffer);
	std::cout << "Enter your nick name:";
	getline(std::cin, buffer);
	setNickName(buffer);
	std::cout << "Please enter the phone number:";
	getline(std::cin, buffer);
	if (IsAlnumForString(buffer))
		setPhoneNumber(buffer);
	std::cout << "Enter your darkest secret:";
	getline(std::cin, buffer);
	setDarkestSecret(buffer);
}

void	Contact::setIndex(int i)
{
	this->index = i;
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickName()
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}

int	Contact::getIndex()
{
	return (this->index);
}
