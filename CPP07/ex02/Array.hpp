#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class	Array
{
	private:
		T*				_array;
		unsigned int	_arraySize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array&	operator=(const Array& other);

		T&				operator[](int index) const;
		unsigned int	size() const;

};

# include "Array.tpp"

#endif