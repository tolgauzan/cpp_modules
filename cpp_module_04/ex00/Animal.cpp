/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:18:25 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:18:25 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
	: _type("Animal")
{
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
	: _type(other._type)
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "[Animal] makeSound().. !" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}