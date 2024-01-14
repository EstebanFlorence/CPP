#include <sstream>
#include "Dog.hpp"
#include "Cat.hpp"

#define NUM_OF_ANIMALS 4

int main()
{
	std::cout << BOLD "Test 1:" CLR_RMV << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << BOLD "Test 2:" CLR_RMV << std::endl;
	const Animal*	animals[NUM_OF_ANIMALS];
	for (int i = 0; i < NUM_OF_ANIMALS; i++)
	{
		(i < NUM_OF_ANIMALS / 2) ? 
			animals[i] = new Dog() : animals[i] = new Cat();
		std::cout << animals[i]->getType() << " " << i + 1 << ":" << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < NUM_OF_ANIMALS; i++)
		delete animals[i];

	std::cout << BOLD "Test 3:" CLR_RMV << std::endl;
	Dog basicDog;
	{
		Dog tmpDog = basicDog;
	}
	Cat basicCat;
	{
		Cat tmpCat = basicCat;
	}

	return 0;
}
