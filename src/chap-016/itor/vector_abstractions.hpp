#ifndef VECTOR_ABSTRACTIONS_HPP
#define VECTOR_ABSTRACTIONS_HPP

#include <utility>
#include <stdexcept>

#include "itor_abstractions.hpp"

namespace Containers
{
	template<class T>
	class VectorItor;

	//Declarations
	//Vector container
	template<class T>
	class Vector
	{
		T *_values;	
		size_t _next_index;
		size_t _capacity;

	public:
		Vector(size_t capacity);

		size_t get_size() const;
		size_t get_capacity() const;

		T &operator[](size_t index);
		void push_back(T&& value);

		~Vector();
	};

	//Vector iterator
	template<class T>
	class VectorItor : public Itor<T>
	{
		Vector<T> &_vector;
		size_t _next_index;
	public:
		VectorItor(Vector<T> &vector);
		VectorItor(Vector<T> &&vector);

		T *first() override;
		T *next() override;
	};

	//Implementation
	//Vector implementation
	template<class T>
	Vector<T>::Vector(size_t capacity) : _next_index(0), _capacity(capacity), _values(new T[capacity])
	{
	}

	template<class T>
	size_t Vector<T>::get_size() const
	{
		return _next_index;
	}

	template<class T>
	size_t Vector<T>::get_capacity() const
	{
		return _capacity;
	}

	template<class T>
	T &Vector<T>::operator[](size_t index)
	{
		if(index > _next_index - 1)
			throw std::out_of_range("Index exceeds vector size.");

		return _values[index];
	}

	template<class T>
	void Vector<T>::push_back(T&& value)
	{
		if(_next_index >= _capacity)
			throw std::length_error("Vector capacity exceeded.");
		_values[_next_index++] = value;
	}

	template<class T>
	Vector<T>::~Vector()
	{
		delete[] _values;
	}
	//Vector iterator implementation
	template<class T>
	VectorItor<T>::VectorItor(Vector<T> &vector) : _vector(vector), _next_index(0)
	{
	}

	template<class T>
	T *VectorItor<T>::first()
	{
		if(_next_index >= _vector.get_size())
			return nullptr;

		return &_vector[_next_index++];
	}

	template<class T>
	T *VectorItor<T>::next()
	{
		if(_next_index >= _vector.get_size())
			return nullptr;

		return &_vector[_next_index++];
	}
}
#endif
