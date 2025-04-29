/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:10:41 by sebasari          #+#    #+#             */
/*   Updated: 2025/04/29 20:08:57 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"

class SHRUBBERYCREATIONFORM:public AForm
{
private:
	std::string	name;
	int			gradeS;
	int			gradeE;
public:
	SHRUBBERYCREATIONFORM();
	~SHRUBBERYCREATIONFORM();
	SHRUBBERYCREATIONFORM(const SHRUBBERYCREATIONFORM& original);
public:
	SHRUBBERYCREATIONFORM& operator=(const SHRUBBERYCREATIONFORM& S);	
};


#endif