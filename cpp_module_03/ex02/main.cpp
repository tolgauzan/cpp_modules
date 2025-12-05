/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:58:43 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 00:58:43 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

static void	testCreateDestroy()
{
	FragTrap	ch1;
	FragTrap	ch2("IronMan");
	FragTrap	ch3(ch2);
	ch1 = ch3;
}

static void	testAttack()
{
	FragTrap	character("Hulk");

	for (int i = 0; i < 5; ++i)
		character.attack("Thanos");
	character.attack("Thanos");
	character.takeDamage(70);
	character.highFivesGuys();
	character.beRepaired(25);
}

static void	testTakeDamage()
{
	FragTrap	character("Thor");

	character.highFivesGuys();
	for (int i = 0; i < 4; ++i)
		character.takeDamage(5);
	character.takeDamage(5);
	character.highFivesGuys();
	character.attack("Loki");
	character.beRepaired(15);
}

static void	testBeRepair()
{
	FragTrap	character("Freya");

	character.highFivesGuys();
	for (int i = 0; i < 3; i++)
	{
		character.attack("Monster");
		character.takeDamage(10);
	}
	for (int i = 0; i < 4; i++)
		character.beRepaired(5);
	character.highFivesGuys();
}

static void	testHighFives()
{
	FragTrap character("SpiderMan");

	character.highFivesGuys();
	character.takeDamage(100);
	character.highFivesGuys();
}

int	main()
{
	std::string	headers[5] = {
		"CONSTRUCTOR / COPY / ASSIGNMENT / DESTRUCTOR",
		"ATTACK",
		"TAKE DAMAGE",
		"BE REPAIR",
		"HIGH FIVES GUYS"
	};
	void	(*tests[5])() = {
		testCreateDestroy,
		testAttack,
		testTakeDamage,
		testBeRepair,
		testHighFives
	};
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "TEST " << i + 1 << " " << headers[i] << std::endl;
		tests[i]();
		std::cout << std::endl;
	}
	return (0);
}
