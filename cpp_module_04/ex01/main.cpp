/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:22:54 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/06 04:22:54 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_SIZE 4
#define IDEA_COUNT 2

int	main()
{
	Animal*		animals[ANIMAL_SIZE];

	std::cout << "\n-- TEST - CREATE ANIMALS CONSTRUCTOR --\n" << std::endl;
	for (int i = 0; i < ANIMAL_SIZE; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "\n-- TEST - ALL ANIMALS SET IDEA--\n" << std::endl;
	for (int i = 0; i < ANIMAL_SIZE; i++)
	{
		Dog*	dog = dynamic_cast<Dog*>(animals[i]);
		Cat*	cat = dynamic_cast<Cat*>(animals[i]);

		if (dog)
		{
			for (int j = 0; j < IDEA_COUNT; j++)
				dog->setIdea(j, "[DOG] I have an idea ");
		}
		else if (cat)
		{
			for (int j = 0; j < IDEA_COUNT; j++)
				cat->setIdea(j, "[CAT] I have an idea ");
		}
	}

	std::cout << "\n-- TEST - ALL ANIMALS GET IDEA--\n" << std::endl;
	for (int i = 0; i < ANIMAL_SIZE; i++)
	{
		Dog*	dog = dynamic_cast<Dog*>(animals[i]);
		Cat*	cat = dynamic_cast<Cat*>(animals[i]);

		if (dog)
		{
			std::cout << "-- DOG : " << i << " --" << std::endl;
			for (int j = 0; j < IDEA_COUNT; j++)
				std::cout << dog->getIdea(j) << j <<  std::endl;
		}
		else if (cat)
		{
			std::cout << "-- CAT : " << i << " --" << std::endl;
			for (int j = 0; j < IDEA_COUNT; j++)
				std::cout << cat->getIdea(j) << j <<  std::endl;
		}
	}

	std::cout << "\n-- TEST - ALL ANIMALS makeSounds() --\n" << std::endl;
	for (int i = 0; i < ANIMAL_SIZE; i++)
	{
		std::cout << " Animal : " << i << " --" << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	std::cout << "\n-- TEST - DEEPCOPY --\n" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->setIdea(0, "ORIGINAL IDEA");
	Dog* copyDog = new Dog(*originalDog);
	copyDog->setIdea(0, "COPIED IDEA");

	std::cout << "\nOriginal Dog idea 0: " << originalDog->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea 0: " << copyDog->getIdea(0) << std::endl;

	std::cout << "\n-- TEST - ASSIGNMENT OPERATOR --\n" << std::endl;
	Dog	assignedDog;
	if (assignedDog.getIdea(0).empty())
		std::cout << "AssingedDog value is empty" << std::endl;
	assignedDog = *copyDog;
	std::cout << "CopyDog idea 0: " << copyDog->getIdea(0) << std::endl;
	std::cout << "AssignedDog idea 0: " << assignedDog.getIdea(0) << std::endl;
	std::cout << std::endl;

	delete originalDog;
	delete copyDog;

	std::cout << "\n-- TEST - ALL ANIMALS DELETE DESTRUCTOR --\n" << std::endl;
	for (int i = 0; i < ANIMAL_SIZE; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
    return 0;
}
