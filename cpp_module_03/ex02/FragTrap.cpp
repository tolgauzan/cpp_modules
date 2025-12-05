/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:00:01 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 01:00:01 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] : " << _name;
	if (_hitPoints == 0)
		std::cout << " has no hit points left and can't give a high five!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << " has no energy points left and can't give a high five!" << std::endl;
	else
		std::cout << " says: High five, guys!" << std::endl;
}
