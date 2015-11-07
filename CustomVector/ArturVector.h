#ifndef _ARTURVECTOR_H_
#define _ARTURVECTOR_H_

namespace artur
{
	template<typename T>
	class arturVector
	{
		size_t _size; //number of elements
		T* _elements; //elements with generic types
		T* _dummy;
	public:
		arturVector(); //default - creates container with no elements
		arturVector(int n); //creates container with n elements
		arturVector(int n, const T& t); //creates container with n elements initialized to value t
		arturVector(const arturVector& aV); //copies the content of container aV into the current object
		~arturVector(); //destroys the container
		arturVector& operator=(const arturVector& aV); //copies the contents of container aV into the current object
		size_t size() const; //returns the number of elements in the current object
		bool empty() const; //returns true if the current object has no elements
		T& operator[](size_t i); //returns a reference to element i
		const T& operator[](size_t i) const; //returns an unmodifaible reference to element i
		T& at(size_t i); //returns a reference to element checking bounds
		const T& at(size_t i) const; //returns an unmodifaible reference to element checking bounds
		T& front(); //returns a reference to the first element
		const T& front() const; //returns an unmodifiable reference to the first element
		T& back(); //returns a reference to the last element
		const T& back() const; //returns an unmodifiable reference to the last element
		void push_back(const T& t); //adds element t after the last element in the container
		void pop_back(); //removes the last element from the container
		void clear(); //removes all elements from the container
	};
}

#endif