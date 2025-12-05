/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:28:59 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/01 00:28:59 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>

int	printError(const std::string& message)
{
	std::cout << "Error : " << message << std::endl;
	return (1);
}

int	checkArguments(int ac, char **av)
{
	if (ac < 4 || ac > 4)
		return (printError("Usage: ./replace <filename> <s1> <s2>"));
	if (!av[1] || !*av[1])
		return (printError("<filename> cannot be empty"));
	if (!av[2] || !*av[2])
		return (printError("<s1> cannot be empty"));
	return (0);
}

std::string	generateFilename()
{
	std::ostringstream	oss;
	std::string			filename;

	do
	{
		oss.str("");
		oss << ".replace.tmp42" << std::rand() << std::time(0);
		filename = oss.str();
	} while (std::ifstream(filename.c_str()).good());
	return (filename);
}

int	replace(std::ifstream& in, std::ofstream& out, const std::string& s1, const std::string& s2)
{
	std::string				line;
	std::string::size_type	pos;
	int						ret = 0;

	while (std::getline(in, line))
	{
		if (s1 != s2)
		{
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
		}
		out << line;
		if (!in.eof())
			out << '\n';
		if (out.fail() || out.bad())
		{
			ret = printError("Could not write to temp output file");
			break ;
		}
	}
	if (!in.eof() && (in.fail() || in.bad()))
		ret = printError("Could not read from input file");
	return (ret);
}

int	replaceFile(const std::string& inFilename, const std::string& s1, const std::string& s2)
{
	std::string		tempOutFilename;
	std::string		outFilename;
	std::ifstream	in;
	std::ofstream	out;

	in.open(inFilename.c_str());
	if (!in.is_open())
		return (printError("Could not open input file"));
	tempOutFilename = generateFilename();
	out.open(tempOutFilename.c_str());
	if (!out.is_open())
		return (printError("Could not create temp output file"));
	if (replace(in, out, s1, s2) != 0)
	{
		if (std::remove(tempOutFilename.c_str()) != 0)
			printError("Temporary file could not be deleted");
		return (1);
	}
	outFilename = inFilename + ".replace";
	if (std::rename(tempOutFilename.c_str(), outFilename.c_str()) != 0)
	{
		if (std::remove(tempOutFilename.c_str()) != 0)
			printError("Temporary file could not be deleted");
		return (printError("Could not rename temp file to final file"));
	}
	return (0);
}

int	main(int ac, char **av)
{
	long	seed = static_cast<long>(std::time(0));
	int		trash;
	
	seed += reinterpret_cast<long>(&trash);
	std::srand(static_cast<unsigned int>(seed));
	if (checkArguments(ac, av))
		return (1);
	return (replaceFile(av[1], av[2], av[3]));
}
