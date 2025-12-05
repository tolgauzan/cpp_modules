/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:34 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:34 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(const std::string& name, Weapon&	weapon);
		~HumanA();

		void	attack(void) const;
};

#endif
