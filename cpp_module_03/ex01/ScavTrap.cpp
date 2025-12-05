/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:21:04 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 00:21:04 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "[ScavTrap] : " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " has no hit points left and can't attack!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << " has no energy points left and can't attack!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << " attacks angrily " << target << ", causing [" << _attackDamage << "] points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] : " << _name;
	if (_hitPoints == 0)
		std::cout << " has no hit points left and cannot enter Gate Keeper mode!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << " has no energy points left and cannot enter Gate Keeper mode!" << std::endl;
	else
		std::cout << " is now in Gate keeper mode!" << std::endl;
}
