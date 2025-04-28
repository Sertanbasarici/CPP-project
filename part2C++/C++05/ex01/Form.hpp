/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/03/19 14:23:50 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string	const	name;
	bool				sign;
	int const			gradeS;
	int const			gradeE;
public:
	Form();
	~Form();
	Form(const Form& original);
public:
	std::string		getName() const;
	bool			getSign() const;
	int				getGradeS() const;
	int				getGradeE() const;
	void			beSigned(Bureaucrat& b);
public:
	Form& operator=(const Form& f);
};
std::ostream& operator<<(std::ostream& COUT, const Form& b);
#endif