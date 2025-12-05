/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:36 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:36 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <cstddef>

HumanB::HumanB(const std::string& name)
	: _name(name), _weapon(NULL)
{
	std::cout << "HumanB " << _name << " created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << _name << " destroyed" << std::endl;
}

void	HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack " << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
