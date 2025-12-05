/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:03:50 by tuzan             #+#    #+#             */
/*   Updated: 2025/10/28 21:03:50 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_countContact;
		int		_nextIndex;
		bool	_running;

		void	_abort();
		bool	_getInput(const std::string& prompt, std::string& output);
		bool	_getValidPhoneNumber(const std::string& prompt, std::string& output);
		void	_printContactList() const;

	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();
		void	exit();
		bool	isRunning() const;
};

#endif
