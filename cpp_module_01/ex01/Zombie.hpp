/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:20 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:20 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();

		void	setName(const std::string& name);
		void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
