#include <sstream>
#include "Dog.hpp"
#include "Cat.hpp"

#define NUM_OF_ANIMALS 4

int main()
{
	// const AAnimal*	animal = new AAnimal();

	const AAnimal*	animals[NUM_OF_ANIMALS];

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		(i < NUM_OF_ANIMALS / 2) ? 
			animals[i] = new Dog() : animals[i] = new Cat();
		std::cout << animals[i]->getType() << " " << i + 1 << ":" << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
		delete animals[i];

	return 0;
}
