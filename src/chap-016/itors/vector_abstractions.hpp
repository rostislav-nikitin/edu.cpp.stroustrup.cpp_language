#ifndef VECTOR_ABSTRACTIONS_HPP
#define VECTOR_ABSTRACTIONS_HPP

#include <limits>
#include <utility>
#include <stdexcept>

#include "itor_abstractions.hpp"

namespace Containers
{
	template<class T, class Storage>
	class VectorItor;

	//Declarations
	//Vector container
	template<class T>
	class Vector
	{
		unsigned int CAPACITY_MULTIPLIER = 2;

		size_t _next_index;
		size_t _capacity;
		T *_values;	

		void deep_copy(Vector<T> &vector);
		size_t calculate_new_capacity();
	public:
		Vector(size_t capacity = 8U);
		Vector(Vector const &vector);
		Vector(Vector &vector);
		Vector(Vector &&vector);

		size_t get_size() const;
		size_t get_capacity() const;
		size_t get_free() const;

		void reserve(size_t new_capacity);

//		T* begin();
//		T* end();

		T &operator[](size_t index);
		Vector<T> &operator=(Vector &vector);
		Vector<T> &operator=(Vector &&vector);

		void push_back(T &value);
		void push_back(T &&value);
		
		T &insert_before(int index, T &value);
		T &insert_before(int index, T &&value);

		void remove(int index);

		~Vector();
	};

	//Storages
	template<class T>
	class IVectorStorage
	{
	public:
		virtual Vector<T> &get() = 0;
	};

	template<class T>
	class VectorStorageByRef : public IVectorStorage<T>
	{
		Vector<T> &_vector;
	public:
		VectorStorageByRef(Vector<T> &vector);

		Vector<T> &get() override;
	};

	template<class T>
	VectorStorageByRef<T>::VectorStorageByRef(Vector<T> &vector) : _vector(vector)
	{
	}

	template<class T>
	Vector<T> &VectorStorageByRef<T>::get()
	{
		return _vector;
	}

	template<class T>
	class VectorStorageByValue : public IVectorStorage<T>
	{
		Vector<T> _vector;
	public:
		VectorStorageByValue(Vector<T> vector);

		Vector<T> &get() override;
	};

	template<class T>
	VectorStorageByValue<T>::VectorStorageByValue(Vector<T> vector) : _vector(vector)
	{
	}

	template<class T>
	Vector<T> &VectorStorageByValue<T>::get()
	{
		return _vector;
	}

	//Vector iterator
	template<class T>
	class VectorReverseItor;

//	template<class T>
	template<class T, class StorageStrategy = VectorStorageByRef<T>>
	class VectorItor : public Itor<T>
	{
		friend class VectorReverseItor<T>;

		StorageStrategy _storage;
		//Vector<T> &_vector;
		size_t _next_index;
	public:
		typedef T value_type;
		typedef T* iterator;

		VectorItor(Vector<T> &vector);
		VectorItor(Vector<T> &&vector);

		T *first() override;
		T *next() override;
	};

	//Vector back iterator
	template<class T>
	class VectorReverseItor : public ReverseItor<T>
	{
		Vector<T> &_vector;
		size_t _next_index;
	public:
		VectorReverseItor(Vector<T> &vector);
		VectorReverseItor(Vector<T> &&vector);

		T *first() override;
		T *next() override;
		std::unique_ptr<Itor<T>> get_base() override;
	};

	//Implementation
	//Vector implementation
	template<class T>
	void Vector<T>::deep_copy(Vector &vector)
	{
		for(size_t idx = 0; idx < vector._next_index; ++idx)
		{
			_values[idx] = vector._values[idx];
		}
	}

	template<class T>
	size_t Vector<T>::calculate_new_capacity()
	{
		size_t ret;

		if(_capacity > 0)
			ret = _capacity * CAPACITY_MULTIPLIER;
		else
			ret = 1 * CAPACITY_MULTIPLIER;

		return ret;
	}

	template<class T>
	Vector<T>::Vector(size_t capacity) : _next_index(0), _capacity(capacity), _values(new T[capacity])
	{
	}

	template<class T>
	Vector<T>::Vector(Vector const &vector) : _next_index(vector._next_index), _capacity(vector._capacity), _values(new T[vector._capacity])
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		deep_copy(vector);
	}

	template<class T>
	Vector<T>::Vector(Vector &vector) : _next_index(vector._next_index), _capacity(vector._capacity), _values(new T[vector._capacity])
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		deep_copy(vector);
	}

	template<class T>
	Vector<T>::Vector(Vector &&vector) : _next_index(vector._next_index), _capacity(vector._capacity), _values(vector._values)
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		vector._capacity = 0;
		vector._next_index = 0;
		vector._values = nullptr;
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
	size_t Vector<T>::get_free() const
	{
		return _capacity - _next_index;
	}

	template<class T>
	void Vector<T>::reserve(size_t new_capacity)
	{
		if(_next_index > new_capacity)
			throw std::out_of_range("New capacity less then items in the vector.");
		T *new_values = new T[new_capacity];
		for(size_t idx = 0; idx < _next_index; ++idx)
		{
			new_values[idx] = _values[idx];
		}

		delete _values;
		_values = new_values;
		_capacity = new_capacity;
	}
/*
	T* begin()
	{
		if(get_size() < 1)
			throw std::out_of_range("Vector limits exceeded.");

		return &_values[0];
	}

	T* end()
	{
		if(get_size() < 1)
			throw std::out_of_range("Vector limits exceeded.");
		
		return &_values[sizeof(_values) / sizeof(T) - 1]; 
	}
*/
	template<class T>
	T &Vector<T>::operator[](size_t index)
	{
		if(index >= _next_index)
			throw std::out_of_range("Index exceeds vector size.");

		return _values[index];
	}

	template<class T>
	Vector<T> &Vector<T>::operator=(Vector &vector)
	{
		if(&vector == this)
			return *this;

		_capacity = vector._capacity;
		_next_index = vector._next_index;
		deep_copy(vector);

		return *this;
	}

	template<class T>
	Vector<T> &Vector<T>::operator=(Vector &&vector)
	{
		if(&vector == this)
			return *this;

		_capacity = vector._capacity;
		_next_index = vector._next_index;
		_values = vector._values;

		vector._capacity = 0;
		vector._next_index = 0;
		vector._values = nullptr;

		return *this;
	}

	template<class T>
	void Vector<T>::push_back(T&& value)
	{
		if(_next_index >= _capacity)
		{
			//throw std::length_error("Vector capacity exceeded.");
			reserve(_capacity * 2);
		}

		_values[_next_index++] = value;
	}

	template<class T>
	void Vector<T>::push_back(T &value)
	{
		if(_next_index >= _capacity)
		{
			//throw std::length_error("Vector capacity exceeded.");
			reserve(calculate_new_capacity());
		}

		_values[_next_index++] = value;
	}

	template<class T>
	T &Vector<T>::insert_before(int index, T &value)
	{
		if(get_free() < 1)
		{
			//throw std::length_error("Vector capacity exceeded.");
			reserve(calculate_new_capacity());
		}
		if(index >= _next_index)
			throw std::out_of_range("Index out of range.");

		for(size_t idx = _next_index; idx > index; --idx)
		{
			_values[idx] = _values[idx - 1];
		}

		_values[index] = value;
		++_next_index;

		return _values[index];
	}

	template<class T>
	T &Vector<T>::insert_before(int index, T &&value)
	{
		if(get_free() < 1)
		{
			//throw std::length_error("Vector capacity exceeded.");
			reserve(calculate_new_capacity());
		}
		if(index >= _next_index)
			throw std::out_of_range("Index out of range.");

		for(size_t idx = _next_index; idx > index; --idx)
		{
			_values[idx] = _values[idx - 1];
		}

		_values[index] = value;
		++_next_index;

		return _values[index];
	}

	template<class T>
	void Vector<T>::remove(int index)
	{
		if(index >= _next_index)
			throw std::out_of_range("Index out of range.");

		for(size_t idx = index; idx < (_next_index - 1); ++idx)
		{
			_values[idx] = _values[idx + 1];
		}

		--_next_index;
	}

	template<class T>
	Vector<T>::~Vector()
	{
		delete[] _values;
	}

	//Vector iterator implementation
	template<class T, class Storage>
	VectorItor<T, Storage>::VectorItor(Vector<T> &vector) : _storage(vector), _next_index(0)
	{
	}

	template<class T, class Storage>
	T *VectorItor<T, Storage>::first()
	{
		_next_index = 0;

		if(_next_index >= _storage.get().get_size())
			return nullptr;

		return &_storage.get()[_next_index++];
	}

	template<class T, class Storage>
	T *VectorItor<T, Storage>::next()
	{
		if(_next_index >= _storage.get().get_size())
			return nullptr;

		return &_storage.get()[_next_index++];
	}

	//Vector back iterator
	template<class T>
	VectorReverseItor<T>::VectorReverseItor(Vector<T> &vector) : _vector(vector), _next_index(vector.get_size() - 1)
	{
	}

	template<class T>
	VectorReverseItor<T>::VectorReverseItor(Vector<T> &&vector) : _vector(vector), _next_index(vector.get_size() - 1)
	{
	}

	template<class T>
	T *VectorReverseItor<T>::first()
	{
		_next_index = _vector.get_size() - 1;
		if(_next_index == std::numeric_limits<size_t>::max())
			return nullptr;

		return &_vector[_next_index--];
	}

	template<class T>
	T *VectorReverseItor<T>::next()
	{
		if(_next_index == std::numeric_limits<size_t>::max())
			return nullptr;
		return &_vector[_next_index--];
	}
	
	template<class T>
	std::unique_ptr<Itor<T>> VectorReverseItor<T>::get_base()
	{
		VectorItor<T> *result = new VectorItor<T>(_vector);

		result->_next_index = _next_index + 1;

		return std::unique_ptr<Itor<T>>(static_cast<Itor<T> *>(result));
	}
}
#endif
