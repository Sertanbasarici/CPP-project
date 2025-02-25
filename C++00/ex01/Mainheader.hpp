/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mainheader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:33:01 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/13 12:38:46 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

#define MAX_SIZE 2

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

bool	IsAlphaForString(std::string string);
bool	IsAlnumForString(std::string string);
bool	IsdigitForString(std::string string);

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	int			index;
public:
	void			EnterContacts();
	void			setFirstName(std::string firstName);
	void			setLastName(std::string lastName);
	void			setNickName(std::string nickName);
	void			setPhoneNumber(std::string phoneNumber);
	void			setDarkestSecret(std::string darkestSecret);
	void			setIndex(int i);
	std::string		getFirstName();
	std::string		getLastName();
	std::string		getNickName();
	std::string		getPhoneNumber();
	std::string		getDarkestSecret();
	int				getIndex();
};

class PhoneBook
{
private:
	Contact	contacts[MAX_SIZE];
	int		index;
public:
	void	AddPhonebook();
	void	SearchInPhoneBook(PhoneBook myPhoneBook);
	void	ShowInfos(int index);
	void	setIndex(int index);
};
#endif