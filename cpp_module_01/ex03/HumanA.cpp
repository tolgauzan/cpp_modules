/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:32 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:32 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << _name << " created" << std::endl;
	std::cout << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << _name << " destroyed" << std::endl;
}

void	HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}