/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:33:18 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/13 01:13:56 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argn, char **argv)
{
	std::string	str;
	int			i;

	i = 1;
	if (argn <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			str = argv[i];
			for (size_t j = 0;j<str.length();j++)
				std::cout << (char)std::toupper(str[j]);
			if (i != argn - 1)
				std::cout << " ";
			i++;	
		}
		std::cout << std::endl;
	}
	
}