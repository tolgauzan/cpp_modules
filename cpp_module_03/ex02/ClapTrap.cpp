/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:52:27 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/05 23:52:27 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assingment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "[ClapTrap] : " << _name;
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
	std::cout << " attacks " << target << ", causing [" << _attackDamage << "] points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[ClapTrap] : " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " is already dead and cannot take more damage! " <<  std::endl;
		return ;
	}
	std::cout << " takes [" << amount << "] points of damage!";
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << " and has died!";
	}
	else
		_hitPoints -= amount;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	maxHitPoints = std::numeric_limits<unsigned int>::max();
	unsigned int	repairCount;

	std::cout << "[ClapTrap] : " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " has no hit points left and can't repair! " << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << " has no energy points left and can't repair! " << std::endl;
		return ;
	}
	if (amount > (maxHitPoints - _hitPoints))
		repairCount = maxHitPoints - _hitPoints;
	else
		repairCount = amount;
	if (repairCount == 0)
		std::cout <<  " is already at maximum hit points! No repair needed!" << std::endl;
	else
	{
		std::cout <<  " is repaired by [" << repairCount << "] points!" << std::endl;
		_hitPoints += repairCount;
		_energyPoints -= 1;
	}
}
