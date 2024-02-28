#include "MutantStack.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	std::cout << "Test 1" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top : " << mstack.top() << " (popped)" << std::endl;

	mstack.pop();

	std::cout << "size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::cout << "\nTest 2" << std::endl;
	MutantStack<int>	mStack;

	srand(static_cast<int>(std::time(0)));

	for (int i = 0; i < 15; i++)
		mStack.push(rand() % 100);

    std::cout << "Testing forward iterator:\n";
	for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

    std::cout << "Testing const forward iterator:\n";
	const MutantStack<int>	constMStack(mStack);
	for (MutantStack<int>::const_iterator it = constMStack.cbegin(); it != constMStack.cend(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

    std::cout << "Testing reverse iterator:\n";
	for (MutantStack<int>::reverse_iterator it = mStack.rbegin(); it != mStack.rend(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

    std::cout << "Testing const reverse iterator:\n";
	for (MutantStack<int>::const_reverse_iterator it = constMStack.crbegin(); it != constMStack.crend(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;


	return 0;
}
