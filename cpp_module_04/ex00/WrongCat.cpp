/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:35:24 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:35:24 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
	: WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "[WRONGCAT] MEeeeeowww MrrrrrMrr ! " << std::endl;
}