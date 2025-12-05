/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:21:45 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:21:45 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal()
{
	_type = "Cat";
	std::cout << "[CAT] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "[CAT] Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[CAT] Destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "[CAT] Copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "[CAT] Meoowww mr ! " << std::endl;
}