#include <iostream>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	this->_array = new T[src._size]();
	for (unsigned int i = 0; i < src._size; i++)
		this->_array[i] = src._array[i];
	this->_size = src._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		T* newArray = new T[src._size]();
		for (unsigned int i = 0; i < src._size; i++)
			newArray[i] = src._array[i];
		if (this->_array)
			delete[] this->_array;
		this->_array = newArray;
		this->_size = src._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] this->_array;
}

template <typename T>
const char* Array<T>::TooHighIndex::what() const throw()
{
	return "Error: Index out of bounds";
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw TooHighIndex();
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw TooHighIndex();
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}
