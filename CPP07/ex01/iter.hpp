#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	power(T& num)
{
	num *= num;
}

template <typename T>
void	 printType(const T& element)
{
	std::cout << element << " ";
}

template <typename T, typename F>
void	iter(T* array, const size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif