/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:35:45 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 04:35:45 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "[Brain] default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] Copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "[Brain] Error: index " << index << " out of range!" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "[Brain] Error: index " << index << " out of range!" << std::endl;
		return ("");
	}
	return (_ideas[index]);
}