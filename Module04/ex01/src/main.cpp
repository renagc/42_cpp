/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:21:05 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/08 10:35:58 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main(void)
{
	{
		const Animal *animals[10];
		for (int i = 0; i < 10; ++i)
		{
			if (i % 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (int i = 0; i < 10; ++i) {
			delete animals[i];
		}
		const Cat *cat1 = new Cat();
		const Animal *cat2 = new Cat(*cat1);
		delete cat1;
		delete cat2;
	}
	{
		const Animal *animalA = new Dog();
		const Animal *animalB = new Cat();
		const Animal *animalC;
		const Animal *animalD;
		const Cat *catA = new Cat();
		const Cat *catB;

		animalC = animalA;
		animalD = animalB;

		std::cout << "Brain Adress of CatA: " << &catA->getBrain() << std::endl;
		std::string ideas[100];
		std::string	idea_pre = "catA idea";
		int a;
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = "idea";
			ideas[i].push_back(32);
			a = i + 1;
			if (a == 100)
			{
				ideas[i].append("100");
				break ;
			}
			while (a > 9)
			{
				ideas[i].push_back((a / 10) + 48);
				a = a % 10;
			}
			ideas[i].push_back(a + 48);
		}
		catA->getBrain().setIdeas(ideas);

		for(int i = 0; i < 100; i++)
			std::cout << catA->getBrain().getIdeas()[i] << std::endl;

		catB = catA;
		std::cout << "Brain Adress of CatB: " << &catB->getBrain() << std::endl;
		for(int i = 0; i < 100; i++)
			std::cout << catB->getBrain().getIdeas()[i] << std::endl;
		animalC->makeSound();
		animalD->makeSound();

		delete catA;
		delete animalA;
		delete animalB;
	}
}
