/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:40:03 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:40:03 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	const std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	Harl	harl;
	int		level;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	level = 0;
	while (level < 4 && levels[level] != argv[1])
		level++;
	switch (level)
	{
		case 0:
			harl.complain(levels[0]);
			std::cout << std::endl;
			// fallthrough
		case 1:
			harl.complain(levels[1]);
			std::cout << std::endl;
			// fallthrough
		case 2:
			harl.complain(levels[2]);
			std::cout << std::endl;
			// fallthrough
		case 3:
			harl.complain(levels[3]);
			std::cout << std::endl;
			// fallthrough
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return (1);
	}
	return (0);
}