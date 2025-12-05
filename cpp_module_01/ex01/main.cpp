/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:16 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:16 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie		*horde;
	int			nZombie = 42;
	std::string	name("Terra");

	horde = zombieHorde(nZombie, name);
	if (!horde)
		return (1);
	for (int i = 0; i < nZombie; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}