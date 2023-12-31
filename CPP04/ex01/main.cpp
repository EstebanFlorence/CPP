#include "Dog.hpp"
#include "Cat.hpp"

#define NUM_OF_ANIMALS 4

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;
	// delete i;

	const Animal*	animals[NUM_OF_ANIMALS];
	Brain*	brain[NUM_OF_ANIMALS];

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		(i < NUM_OF_ANIMALS / 2) ? 
			animals[i] = new Dog() : animals[i] = new Cat();
		std::cout << animals[i]->getType() << " " << i + 1 << ":" << std::endl;
		animals[i]->makeSound();

		brain[i] = animals[i]->getBrain();
		for (int j = 0; j < brain[i]->getMaxIdeas(); j++)
		{
			std::stringstream	ss;
			ss << "Idea n. " << j + 1;
			brain[i]->ideas[j] = ss.str();
			std::cout << brain[i]->ideas[j] << std::endl;
		}
	}

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
		delete animals[i];

	return 0;
}
