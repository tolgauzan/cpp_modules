/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:38 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:38 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB(const std::string& name);
		~HumanB();

		void	setWeapon(Weapon& weapon);
		void	attack(void) const;
};

#endif