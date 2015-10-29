#include <iostream>
#include "ArturVector.h"

namespace artur
{
	template<typename T>
	arturVector<T>::arturVector() : _size(0), _elements((T*)0), _dummy((T)-1) {}

	template<typename T>
	arturVector<T>::arturVector(int n) : _size(n), _elements(nullptr) {}

	template<typename T>
	arturVector<T>::arturVector(int n, const T& t) : _size(n), _dummy((T)-1)
	{
		_elements = new T[n];
		for (int i = 0; i < n; i++)
			_elements[i] = t;
	}

	template<typename T>
	arturVector<T>::arturVector(const arturVector& aV)
	{
		//shalow copy
		this->_size = aV._size;
		this->_dummy = aV._dummy;
		//deep copy
		if (aV._elements != nullptr)
		{
			this->_elements = new T[aV._size];
			for (int i = 0; i < aV._size; i++)
				this->_elements[i] = aV._elements[i];
		}
		else
			this->_elements = nullptr;
	}

	template<typename T>
	arturVector<T>::~arturVector() { delete[] _elements; }

	template<typename T>
	arturVector<T>& arturVector<T>::operator=(const arturVector& aV)
	{
		if (this != &aV)
		{
			_size = aV._size; //shallow copy
			_dummy = aV._dummy;

			if (_elements != nullptr)
			{
				delete[] _elements;
				_elements = nullptr;
			}

			if (aV._elements != nullptr)
			{
				_elements = new T[aV._size];
				for (int i = 0; i < aV.size; i++)
					_elements[i] = aV._elements[i];
			}
			else
				_elements = nullptr;
		}

		return *this;
	}

	template<typename T>
	size_t arturVector<T>::size() const { return this->_size; }

	template<typename T>
	bool arturVector<T>::empty() const { return this->_size == 0; }

	template<typename T>
	T& arturVector<T>::operator[](size_t i) { return i >= 0 && i < _size ? _elements[i] : _dummy; }

	template<typename T>
	const T& arturVector<T>::operator[](size_t i) const { return i >= 0 && i < _size ? _elements[i] : _dummy; }

	template<typename T>
	T& arturVector<T>::at(size_t i)
	{
		try {
			if (i >= 0 && i < _size)
				return _elements[i];
			else
				throw "Index is out of bounds";
		}
		catch (const char* msg) {
			std::cout << msg << std::endl;
			return _dummy;
		}
	}

	template<typename T>
	const T& arturVector<T>::at(size_t i) const
	{
		try {
			if (i >= 0 && i < _size)
				return _elements[i];
			else
				throw "Index is out of bounds";
		}
		catch (const char* msg) {
			std::cout << msg << std::endl; 
			return _dummy;
		}
	}

	template<typename T>
	T& arturVector<T>::front() { return _elements[0]; }

	template<typename T>
	const T& arturVector<T>::front() const { return _elements[0]; }

	template<typename T>
	T& arturVector<T>::back() { 
		size_t temp = _size; //we don't want to mess with original _size, so we create temporary variable
		return _elements[temp - 1]; }

	template<typename T>
	const T& arturVector<T>::back() const { 
		size_t temp = _size;
		return _elements[temp - 1];
	}

	template<typename T>
	void arturVector<T>::push_back(const T& t)
	{
		//first step - to create temporary pointer of object, wich has a type T
		T* temp;
		//second step - to allocate memory for him, wich will have one element more than "_elements"
		temp = new T[this->_size + 1];
		//third step - to copy the contents from _elements to it
		int i; //variable for iteration
		for (i = 0; i < _size; i++)
			temp[i] = _elements[i];
		temp[i] = t; //step four - we add object t from parameter to the end of temporary array

		//and now we have to delete the original for recreating it again with one extra element
		delete[] _elements;
		_elements = nullptr;
		//we create our array of elements again
		_elements = new T[this->_size + 1];
		//and we copy whole content 
		for (i = 0; i < (_size + 1); i++)
			_elements[i] = temp[i];

		//we increase the size of array
		_size++;

	}

	template<typename T>
	void arturVector<T>::pop_back()
	{
		//first step - to create a pointer to temporary storage
		T* temp;
		//second step - to allocate the memory
		temp = new T[_size];
		//third step - to copy the content from original array of elements to it
		int i; //iterator variable
		for (i = 0; i < _size; i++)
			temp[i] = _elements[i];
		//fourth step - to delete original array
		delete[] _elements;
		_elements = nullptr;
		//fifth step - create original again, but with decreased size to one
		_elements = new T[_size - 1];
		//sixth step - to copy content back, but without the last element
		for (i = 0; i < (_size - 1); i++)
			_elements[i] = temp[i];
		//seventh step - to delete temporary object
		delete[] temp;
		temp = nullptr;

		//eighth step - to reduce size of array
		_size = _size - 1;
	}

	template<typename T>
	void arturVector<T>::clear()
	{
		delete[] _elements;
		_elements = nullptr;
	}

	/*void temporaryFunction()
	{
		arturVector<double> tempObj;
	} */
}
