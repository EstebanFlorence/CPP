#include <sstream>
#include "Dog.hpp"
#include "Cat.hpp"

#define NUM_OF_ANIMALS 4

int main()
{

	// AAnimal	test;	should give a compile error

	const AAnimal*	animals[NUM_OF_ANIMALS];

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		(i < NUM_OF_ANIMALS / 2) ? 
			animals[i] = new Dog() : animals[i] = new Cat();
		std::cout << animals[i]->getType() << " " << i + 1 << ":" << std::endl;
		animals[i]->makeSound();

		Brain* brain = animals[i]->getBrain();
		for (int j = 0; j < brain->getMaxIdeas(); j++)
		{
			std::stringstream	ss;
			ss << "Idea n. " << j + 1;
			brain->ideas[j] = ss.str();
			std::cout << brain->ideas[j] << std::endl;
		}
	}

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
		delete animals[i];

	return 0;
}
