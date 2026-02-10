#include <iostream>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	this->_array = new T[src._size];
	for (unsigned int i = 0; i < src._size; i++)
		this->_array[i] = src._array[i];
	this->_size = src._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		if (this->_array)
			delete[] this->_array;
		this->_size = src._size;
		if (_size < 0)
			this->_array = NULL;
		else
		{
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}
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
