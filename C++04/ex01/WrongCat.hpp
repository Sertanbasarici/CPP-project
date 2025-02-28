/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:35 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 11:02:47 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat:public WrongAnimal 
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat& original);
public:
    WrongCat&     operator=(const WrongCat& wrongCat);
};

#endif