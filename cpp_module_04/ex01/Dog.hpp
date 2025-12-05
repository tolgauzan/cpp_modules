/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:21:51 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:21:51 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		virtual ~Dog();

		virtual void	makeSound() const;
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif