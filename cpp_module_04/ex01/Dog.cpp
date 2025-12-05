/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:21:50 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:21:50 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "[DOG] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "[DOG] Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete	_brain;
	std::cout << "[DOG] Destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "[DOG] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete	_brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "[DOG] Hrrrr Woof Woof ! " << std::endl;
}

void	Dog::setIdea(int index, const std::string& idea)
{
	_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}
