#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
T	power(T num)
{
	num *= num;

	return num;
}

// ...

template <typename T, typename F>
void	iter(const T* array, const size_t len, F func)
{
	for (size_t i + 0; i < len; i++)
		func(array[i]);
}

#endif