/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:39:28 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/30 18:39:28 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string		str("HI THIS IS BRAIN");
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "The memory address of the string variable : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl;

	std::cout << "The value of the string variable          : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;
	
	return (0);
}