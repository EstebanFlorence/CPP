#include "Array.hpp"

template<class T>
Array<T>::Array()
: _array(NULL),  _arraySize(0)
{}

template<class T>
Array<T>::Array(unsigned int n)
: _array(new T[n]), _arraySize(n)
{}

template<class T>
Array<T>::Array(const Array& copy)
: _array(new T[copy._arraySize]), _arraySize(copy._arraySize)
{
	for (unsigned int i = 0 ; i < _arraySize; i++)
		this->_array[i] = copy._array[i];
}

template<class T>
Array<T>::~Array()
{ delete[] _array; }

template<class T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	delete[] this->_array;
	this->_array = new T[other._arraySize];
	for (int i = 0; i < _arraySize; i++)
		this->_array[i] = other._array[i];
	this->_arraySize = other._arraySize;

	return *this;
}

template<class T>
T&	Array<T>::operator[](int index) const
{
	if (index < 0)
		throw std::out_of_range("Negative Index");
	else if (static_cast<unsigned int>(index) >= this->_arraySize)
		throw std::out_of_range("Index out of bounds");

	return this->_array[index];
}

template<class T>
unsigned int	Array<T>::size() const
{ return _arraySize; }
