/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:33 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 11:07:38 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    std::cout << "Default WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original): WrongAnimal(original)
{
    std::cout << "Copy WrongCat constructor called" << std::endl;
    this->type = original.type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    std::cout << "Copy Assignment of WrongCat operator called" << std::endl;
    if (this != &wrongCat)
    {
        this->type = wrongCat.type;
    }
    return *this;
}