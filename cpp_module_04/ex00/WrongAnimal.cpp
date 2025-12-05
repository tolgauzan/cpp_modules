/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:35:28 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:35:28 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: _type(other._type)
{
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] makeSound().." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}