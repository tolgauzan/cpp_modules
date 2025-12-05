/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:51:18 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/28 20:51:18 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

static void	printMessage(const std::string& message, bool hasNewLine = false)
{
	if (!message.empty())
		std::cout << message;
	if (hasNewLine)
		std::cout << std::endl;
}

static std::string	stringToUpper(std::string message)
{
	for (std::string::size_type i = 0; i < message.length(); i++)
		message[i] = static_cast<char>(std::toupper(message[i]));
	return (message);
}

int	main(int argc, char **argv)
{
	bool	allEmpty = true;

	if (argc < 2)
		printMessage("* LOUD AND UNBEARABLE FEEDBACK NOISE *", true);
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (argv[i][0] == '\0')
				continue ;
			allEmpty = false;
			printMessage(stringToUpper(argv[i]));
		}
		printMessage("", !allEmpty);
	}
	return (0);
}