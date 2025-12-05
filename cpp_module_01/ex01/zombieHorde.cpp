/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:22 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:22 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstddef>

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Invalid N" << std::endl;
		return (NULL);
	}
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}