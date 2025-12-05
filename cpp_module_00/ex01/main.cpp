/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:03:47 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/28 21:03:47 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

static std::string	trimWhitespaces(std::string& str)
{
	std::string::size_type	start;
	std::string::size_type	end;

	start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t\n\r");
	return (str.substr(start, end - start + 1));
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to PhoneBook.." << std::endl;
	while (phoneBook.isRunning())
	{
		std::cout << "Enter [ADD] [SEARCH] [EXIT] : " << std::endl;
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nAborting.." << std::endl;
			break ;
		}
		command = trimWhitespaces(command);
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			phoneBook.exit();
		else
		{
			if (command.empty())
				std::cout << "Invalid empty line!" << std::endl;
			else
				std::cout << "Invalid command!" << std::endl;
			std::cout << "Please try again.." << std::endl;
		}
	}
	return (0);
}
