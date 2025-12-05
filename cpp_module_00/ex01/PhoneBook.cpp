/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:03:48 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/28 21:03:48 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook()
	: _countContact(0), _nextIndex(0), _running(true)
{
	std::cout << "--------------PhoneBook created--------------" << std::endl;
	std::cout << "--------------PhoneBook is running-----------" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "--------------PhoneBook deleted--------------" << std::endl;
}

void	PhoneBook::_abort()
{
	_running = false;
}

bool	PhoneBook::isRunning() const
{
	return (_running);
}

void	PhoneBook::exit()
{
	_abort();
	std::cout << "\n--------------Exiting PhoneBook--------------" << std::endl;
}

static bool	isPrintableStr(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (!std::isprint(static_cast<unsigned char>(str[i])))
		return (false);
	}
	return (true);
}

bool	PhoneBook::_getInput(const std::string& prompt, std::string& output)
{
	std::string::size_type	start;
	std::string::size_type	end;
	std::string				input;

	while (true)
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, input))
		{
			_abort();
			std::cout << "\nAborting.." << std::endl;
			return (false);
		}
		start = input.find_first_not_of(" \t\n\r");
		if (start == std::string::npos)
		{
			std::cout << "Input cannot be empty. Please try again.." << std::endl;
			continue ;
		}
		end = input.find_last_not_of(" \t\n\r");
		output = input.substr(start, end - start + 1);
		if (!isPrintableStr(output))
		{
			std::cout << "Input contains non-printable characters. Please try again.." << std::endl;
			continue ;
		}
		return (true);
	}
}

bool	PhoneBook::_getValidPhoneNumber(const std::string& prompt, std::string& output)
{
	std::string::size_type	count;
	std::string				phone;
	bool					valid;

	while (true)
	{
		if (!_getInput(prompt, phone))
			return (false);
		count = 0;
		valid = true;
		for (std::string::size_type i = 0; i < phone.length(); i++)
		{
			if (i == 0 && phone[i] == '+')
				continue ;
			if (!std::isdigit(static_cast<unsigned char>(phone[i])))
			{
				valid = false;
				break ;
			}
			count++;
		}
		if (valid && count >= 1 && count <= 20)
		{
			output = phone;
			return (true);
		}
		std::cout << "Invalid phone number!" << std::endl;
		std::cout << "Only [1-20] digits (optional + sign at the beginning)" << std::endl;
	}
}

void	PhoneBook::add()
{
	bool	(PhoneBook::*inputFunc)(const std::string&, std::string&);
	void	(Contact::*setters[5])(const std::string&)= {
		&Contact::setFirstName,
		&Contact::setLastName,
		&Contact::setNickName,
		&Contact::setPhoneNumber,
		&Contact::setDarkestSecret
	};
	const std::string	prompts[5] = {
		"Enter first name     :",
		"Enter last name      :",
		"Enter nick name      :",
		"Enter phone number   :",
		"Enter darkest secret :"
	};
	Contact				&contact = _contacts[_nextIndex];
	std::string			input;

	std::cout << "-------------Adding New Contact--------------" << std::endl;
	if (_countContact == 8)
		std::cout << "Phonebook is full\nIt's overwriting the oldest entry." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		inputFunc = (i == 3) ? &PhoneBook::_getValidPhoneNumber : &PhoneBook::_getInput;
		if (!(this->*inputFunc)(prompts[i], input))
			return ;
		(contact.*setters[i])(input);
	}
	_nextIndex = (_nextIndex + 1) % 8;
	if (_countContact < 8)
		_countContact++;
	std::cout << "-----------Added New Contact [" << _countContact << "/8]-----------" << std::endl;
}

static std::string	formatColumn(const std::string& column)
{
	if (column.length() > 10)
		return (column.substr(0, 9) + ".");
	return (column);
}

static void	printRow(const std::string row[], int size)
{
	std::cout << "|";
	for (int i = 0; i < size; i++)
		std::cout << std::setw(10) << std::right << row[i] << "|";
	std::cout << std::endl;
}

void	PhoneBook::_printContactList() const
{
	const std::string	headers[4] = {"Index", "First Name", "Last Name", "Nick Name"};

	std::cout << "\n-----------------Contact List----------------" << std::endl;
	printRow(headers, 4);
	for (int i = 0; i < _countContact; i++)
	{
		const Contact&		contact = _contacts[i];
		const std::string	index = std::string(1, static_cast<char>('0' + (i + 1)));
		const std::string	row[4] = {
			index,
			formatColumn(contact.getFirstName()),
			formatColumn(contact.getLastName()),
			formatColumn(contact.getNickName())
		};
		printRow(row, 4);
	}
	std::cout << "-----------------Contact List----------------\n" << std::endl;
}

void	PhoneBook::search()
{
	std::string	input;
	int			userIndex;

	if (_countContact == 0)
	{
		std::cout << "No contacts to show." << std::endl;
		return ;
	}
	_printContactList();
	if (!_getInput("Enter index to view :", input))
		return ;
	if (input.length() == 1 && std::isdigit(static_cast<unsigned char>(input[0])))
	{
		userIndex = input[0] - '0';
		if (userIndex >= 1 && userIndex <= _countContact)
		{
			_contacts[userIndex - 1].printContact();
			return ;
		}
	}
	std::cout << "Invalid index! Returning to main menu." << std::endl;
}
