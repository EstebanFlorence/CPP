#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		std::cout << "Occurrence not found" << std::endl;
	else
		std::cout << "Occurrence found" << std::endl;

	return it;
}

#endif