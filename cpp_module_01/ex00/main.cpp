/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:02 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:02 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n--Stack Zombies--\n" << std::endl;
	Zombie	z1("Barry");
	z1.announce();

	randomChump("Hope");

	std::cout << "\n--Heap Zombies--\n" << std::endl;
	Zombie	*z2 = new Zombie("Harper");
	z2->announce();
	delete z2;

	Zombie	*z3 = newZombie("Amber");
	z3->announce();
	delete z3;

	return (0);
}
