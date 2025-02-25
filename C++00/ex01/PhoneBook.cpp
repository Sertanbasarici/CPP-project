/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:35:48 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/13 12:45:26 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mainheader.hpp"


void PhoneBook::AddPhonebook()
{
	static int i = 0;
	Contact bufferContact;

	bufferContact.EnterContacts();
	if (i > (MAX_SIZE - 1))
		i = 0;
	if ((bufferContact.getFirstName() == ""
		|| bufferContact.getLastName() == ""
		|| bufferContact.getNickName() == ""
		|| bufferContact.getPhoneNumber() == ""
		|| bufferContact.getDarkestSecret() == ""))
		std::cout << "Invalid entry!!!" << std::endl;
	else
	{
		this->contacts[i] = bufferContact;
		this->contacts[i].setIndex(i);
		i++;
		this->index++;
	}
}

void	PhoneBook::SearchInPhoneBook(PhoneBook myPhoneBook)
{
	std::string	index;
	int			IntIndex;

	std::cout << "     Index|First Name| Last Name| Nick Name" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0;i < this->index && i < MAX_SIZE;i++)
	{
		std::cout << "         " << this->contacts[i].getIndex() << "|";
		std::string fields[3];
		fields[0] = this->contacts[i].getFirstName();
		fields[1] = this->contacts[i].getLastName();
		fields[2] = this->contacts[i].getNickName();
		for (int j = 0; j < 3; j++)
		{
			std::string formattedField = fields[j];
			if (formattedField.length() > 10)
				formattedField = formattedField.substr(0, 9) + ".";
			int padding = 10 - formattedField.length();
			if (j == 2)
				std::cout << std::string(padding, ' ') << formattedField;
			else
				std::cout << std::string(padding, ' ') << formattedField << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "Enter the desired index:";
	getline(std::cin, index);
	std::stringstream(index) >> IntIndex;
	if (!IsdigitForString(index) || IntIndex < 0 || IntIndex >= this->index)
		std::cout << "Invalid entry please enter again!!!" << std::endl; 
	else
		myPhoneBook.ShowInfos(IntIndex);
}

void	PhoneBook::ShowInfos(int index)
{
	size_t	i;

	for (i = 0;i < MAX_SIZE;i++)
		if (this->contacts[i].getIndex() == index)
			break;
	std::cout << this->contacts[i].getFirstName() << std::endl;
	std::cout << this->contacts[i].getLastName() << std::endl;
	std::cout << this->contacts[i].getNickName() << std::endl;
	std::cout << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << this->contacts[i].getDarkestSecret() << std::endl;
}

void	PhoneBook::setIndex(int index)
{
	this->index = index;
}