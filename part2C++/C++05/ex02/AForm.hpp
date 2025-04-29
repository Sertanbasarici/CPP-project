/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/04/29 21:41:13 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string	const	name;
	bool				sign;
	int const			gradeS;
	int const			gradeE;
public:
	AForm();
	virtual ~AForm();
	AForm(const AForm& original);
public:
	std::string		getName() const;
	bool			getSign() const;
	int				getGradeS() const;
	int				getGradeE() const;
	void			beSigned(Bureaucrat& b);
public:
	AForm& operator=(const AForm& f);
};
std::ostream& operator<<(std::ostream& COUT, const Form& b);
#endif