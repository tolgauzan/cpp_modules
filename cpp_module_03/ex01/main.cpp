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

#include "ScavTrap.hpp"
#include <iostream>

static void	testCreateDestroy()
{
	ScavTrap ch1;
	ScavTrap ch2("Warrior");
	ScavTrap ch3(ch2);
	ch1 = ch3;
}

static void	testAttack()
{
	ScavTrap	character("Thor");

	character.guardGate();
	for (int i = 0; i < 5; ++i)
		character.attack("Loki");
	character.attack("Loki");
	character.takeDamage(70);
	character.beRepaired(25);
}

static void	testTakeDamage()
{
	ScavTrap	character("Odin");

	for (int i = 0; i < 4; ++i)
		character.takeDamage(5);
	character.takeDamage(5);
	character.attack("Loki");
	character.beRepaired(15);
	character.guardGate();
}

static void	testBeRepair()
{
	ScavTrap	character("Freya");

	for (int i = 0; i < 3; i++)
	{
		character.attack("Monster");
		character.takeDamage(10);
	}
	character.guardGate();
	for (int i = 0; i < 4; i++)
		character.beRepaired(5);
}

static void	testGuardGate()
{
	ScavTrap	character("Guardian");

	for (int i = 0; i < 20; ++i)
		character.attack("Monster");
	character.guardGate();
	for (int i = 0; i < 30; ++i)
		character.attack("Monster");
	character.guardGate();
	character.takeDamage(100);
	character.guardGate();
}

int	main()
{
	std::string	headers[5] = {
		"CONSTRUCTOR / COPY / ASSIGNMENT / DESTRUCTOR",
		"ATTACK",
		"TAKE DAMAGE",
		"BE REPAIR",
		"GUARD GATE"
	};
	void	(*tests[5])() = {
		testCreateDestroy,
		testAttack,
		testTakeDamage,
		testBeRepair,
		testGuardGate
	};
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "TEST " << i + 1 << " " << headers[i] << std::endl;
		tests[i]();
		std::cout << std::endl;
	}
	return (0);
}
