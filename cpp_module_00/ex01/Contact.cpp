/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:03:43 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/28 21:03:43 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
	: _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact()
{
}

const std::string&	Contact::getFirstName() const
{
	return (_firstName);
}

const std::string&	Contact::getLastName() const
{
	return (_lastName);
}

const std::string&	Contact::getNickName() const
{
	return (_nickName);
}

const std::string&	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

const std::string&	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

void	Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void	Contact::printContact() const
{
	std::cout << "\n---------------Contact Details---------------" << std::endl;
	std::cout << "First Name     : " << getFirstName() << std::endl;
	std::cout << "Last Name      : " << getLastName() << std::endl;
	std::cout << "Nick Name      : " << getNickName() << std::endl;
	std::cout << "Phone Number   : " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << getDarkestSecret() << std::endl;
	std::cout << "---------------Contact Details---------------\n" << std::endl;
}
