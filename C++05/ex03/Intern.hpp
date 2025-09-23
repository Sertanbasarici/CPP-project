/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:50:03 by sebasari          #+#    #+#             */
/*   Updated: 2025/07/11 22:05:19 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& original);
public:
	AForm* makeForm(const std::string &FormName, const std::string &FormTarget);
public:
	Intern&	operator=(const Intern& S);	
};


#endif