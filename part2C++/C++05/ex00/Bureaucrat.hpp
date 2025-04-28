/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:30:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/03/19 12:56:29 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
protected:
	std::string	const	name;
	int					grade;
public:
	Bureaucrat();
	Bureaucrat(const int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& original);
public:
	std::string getName() const;
	int			getGrade() const;
	void		increamentGrade();
	void		decrementGrade();
public:
	Bureaucrat& operator=(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream &COUT, const Bureaucrat& b);
#endif