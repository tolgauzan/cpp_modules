/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:50:33 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/05 23:50:33 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

static void	testCreateDestroy()
{
	ClapTrap ch1;
	ClapTrap ch2("Warrior");
	ClapTrap ch3(ch2);
	ch1 = ch3;
}

static void	testAttack()
{
	ClapTrap	character("Thor");

	for (int i = 0; i < 10; ++i)
		character.attack("Loki");
	character.attack("Loki");
	character.beRepaired(1);
}

static void	testTakeDamage()
{
	ClapTrap	character("Odin");

	for (int i = 0; i < 10; ++i)
		character.takeDamage(1);
	character.takeDamage(1);
	character.attack("Odin");
	character.beRepaired(1);
}

static void	testBeRepair()
{
	ClapTrap	character("Freya");

	for (int i = 0; i < 6; i++)
	{
		character.attack("Monster");
		character.takeDamage(1);
	}
	for (int i = 0; i < 4; i++)
		character.beRepaired(1);
	character.beRepaired(1);
}

int	main()
{
	std::string	headers[4] = {
		"CONSTRUCTOR / COPY / ASSIGNMENT / DESTRUCTOR",
		"ATTACK",
		"TAKE DAMAGE",
		"BE REPAIR"
	};
	void	(*tests[4])() = {
		testCreateDestroy,
		testAttack,
		testTakeDamage,
		testBeRepair
	};
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "TEST " << i + 1 << " " << headers[i] << std::endl;
		tests[i]();
		std::cout << std::endl;
	}
	return (0);
}
