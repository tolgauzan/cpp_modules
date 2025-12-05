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
	: AAnimal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "[CAT] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	: AAnimal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "[CAT] Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete	_brain;
	std::cout << "[CAT] Destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "[CAT] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete	_brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "[CAT] Meoowww mr ! " << std::endl;
}

void	Cat::setIdea(int index, const std::string& idea)
{
	_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}
