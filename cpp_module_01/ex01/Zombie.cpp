/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:18 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:18 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
	: _name("Default")
{
	std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}