/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 03:21:47 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 03:21:47 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		virtual ~Cat();

		virtual void	makeSound() const;
		void	setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};

#endif