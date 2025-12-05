/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:43 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:43 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
	: _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(const std::string& type)
{
	_type = type;
}