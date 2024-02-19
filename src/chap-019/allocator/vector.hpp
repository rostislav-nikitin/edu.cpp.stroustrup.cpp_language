#include "allocator.hpp"
#include "safe_iterator.hpp"

template<class T, class A = Allocator<T>>
class Vector
{
	typedef A allocator_type;

	typedef typename A::value_type value_type;
	typedef typename A::size_type size_type;

	typedef typename A::difference_type  difference_type;
  
	typedef typename A::pointer pointer;
	typedef typename A::const_pointer const_pointer;

  	typedef typename A::reference reference;
  	typedef typename A::const_reference const_reference;

	typedef SafeIterator<value_type> iterator;
	typedef SafeIterator<value_type const> const_iterator;


	A &_allocator;
	int _size;
	int _capacity;

	pointer _items;

	void validate_index(size_type index) const;
	void valudate_capacity() const;
public:

	Vector(size_type count = 0, value_type value = T(), A const &allocator = A());
	~Vector();

	//	Capacity
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	void reserve(size_type value);
	size_type capacity() const;


	//	Element access
	reference at(size_type index);
	const_reference at(size_type index) const;

	reference operator[](size_type index);
	const_reference operator[](size_type index) const;

	reference front();
	const_reference front() const;

	reference back();
	const_reference back() const;

	pointer data();
	
	//	Iterators
	iterator begin();	
	const_iterator begin() const;	

	iterator end();	
	const_iterator end() const;	

	//	Modifiers
	void push_back(value_type item);

	void pop_back();
};

template<class T, class A>
void Vector<T, A>::validate_index(size_type index) const
{
	if(index < 0 || index >= _size)
		throw std::out_of_range("Index out of the bounds.");
}
template<class T, class A>
void Vector<T, A>::valudate_capacity() const
{
	if(_size >= _capacity)
		throw std::length_error("Size out of the capacity.");
}

template<class T, class A>
Vector<T, A>::Vector(size_type count, value_type value, A const &allocator) : _allocator(const_cast<A&>(allocator)), _size(count), _capacity(count?count:8)
{
	_items = _allocator.allocate(_capacity);
	for(int idx = 0; idx < count; ++idx)
	{
  		_allocator.construct(_items + idx, value);
	}
}

template<class T, class A>
Vector<T, A>::~Vector()
{
	for(int idx = 0; idx < _size; ++idx)
	{
  		_allocator.deconstruct(_items + idx);
	}
	_allocator.deallocate(_items, _size * sizeof(T));
}

//	Capacity
template<class T, class A>
bool Vector<T, A>::empty() const
{
	return _size == 0;
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::size() const
{
	return _size;
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::max_size() const
{
	return _capacity;
}

template<class T, class A>
void Vector<T, A>::reserve(size_type value)
{
	//TODO:
	//	* Allocate new chunk of memory
	//	* Move exisiting objects to the new chunk
	//	* Update capacity
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::capacity() const
{
	return _capacity;
}


//	Element access
template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::at(size_type index)
{
	validate_index(index);
	return *(_items + index);
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::at(size_type index) const
{
	validate_index(index);
	return *(_items + index);
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::operator[](size_type index)
{
	return *(_items + index);	
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::operator[](size_type index) const
{
	return *(_items + index);	
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::front()
{
	return *_items;
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::front() const
{
	return *_items;
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::back()
{
	return *(_items + _size - 1);
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::back() const
{
	return *(_items + _size - 1);
}

template<class T, class A>
typename Vector<T, A>::pointer Vector<T, A>::data()
{
	return _items;
}
	
//	Iterators
template<class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::begin()
{
	return SafeIterator(_items);
}

template<class T, class A>
typename Vector<T, A>::const_iterator Vector<T, A>::begin() const
{
	return SafeIterator(_items);
}

template<class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::end()
{
	return SafeIterator<value_type>(*this);
}

template<class T, class A>
typename Vector<T, A>::const_iterator Vector<T, A>::end() const
{
	return SafeIterator<value_type>(*this);
}

//	Modifiers
template<class T, class A>
void Vector<T, A>::push_back(value_type item)
{
	valudate_capacity();

	_items[_size] = item;
	++_size;
}

template<class T, class A>
void Vector<T, A>::pop_back()
{
	_allocator.deconstruct(_items + _size - 1);
	--_size;
}














// Pointer type
template<class T, class A>
class Vector<T*, A>
{
	typedef A allocator_type;

	typedef typename A::value_type value_type;
	typedef typename A::size_type size_type;

	typedef typename A::difference_type  difference_type;
  
	typedef typename A::pointer pointer;
	typedef typename A::const_pointer const_pointer;

  	typedef typename A::reference reference;
  	typedef typename A::const_reference const_reference;

	typedef SafeIterator<T *> iterator;
	typedef SafeIterator<T const *> const_iterator;


	A &_allocator;
	int _size;
	int _capacity;
public:

	Vector(size_type count = 0, T value = T(), A const &allocator = A());

	//	Capacity
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	void reserve(size_type value);
	size_type capacity() const;


	//	Element access
	reference at(size_type index);
	const_reference at(size_type index) const;

	reference operator[](size_type index);
	const_reference operator[](size_type index) const;

	reference front();
	const_reference front() const;

	reference back();
	const_reference back() const;

	pointer data();
	
	//	Iterators
	iterator begin();	
	const_iterator begin() const;	

	iterator end();	
	const_iterator end() const;	

	//	Modifiers
	void push_back(value_type item);
	void push_back(reference item);

	void pop_back();
};
/*
template<class T, class A>
Vector<T, A>::Vector(size_type count, T value, A const &allocator) : _allocator(const_cast<A&>(allocator)), _size(count), _capacity(count?count:8)
{
	_allocator.allocate(10);
}


//	Capacity
template<class T, class A>
bool Vector<T, A>::empty() const
{
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::size() const
{
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::max_size() const
{
}

template<class T, class A>
void Vector<T, A>::reserve(size_type value)
{
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::capacity() const
{
}


//	Element access
template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::at(size_type index)
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::at(size_type index) const
{
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::operator[](size_type index)
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::operator[](size_type index) const
{
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::front()
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::front() const
{
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::back()
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::back() const
{
}

template<class T, class A>
typename Vector<T, A>::pointer Vector<T, A>::data()
{
}
	
//	Iterators
template<class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::begin()
{
}

template<class T, class A>
typename Vector<T, A>::const_iterator Vector<T, A>::begin() const
{
}

template<class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::end()
{
}

template<class T, class A>
typename Vector<T, A>::const_iterator Vector<T, A>::end() const
{
}

//	Modifiers
template<class T, class A>
void Vector<T, A>::push_back(value_type item)
{
}

template<class T, class A>
void Vector<T, A>::push_back(reference item)
{
}

template<class T, class A>
void Vector<T, A>::pop_back()
{
}
*/











// void* overload

template<class A>
class Vector<void *, A>
{
	typedef A allocator_type;

	typedef typename A::value_type value_type;
	typedef typename A::size_type size_type;

	typedef typename A::difference_type  difference_type;
  
	typedef typename A::pointer pointer;
	typedef typename A::const_pointer const_pointer;

  	typedef typename A::reference reference;
  	typedef typename A::const_reference const_reference;

	typedef SafeIterator<void *> iterator;
	typedef SafeIterator<void const *> const_iterator;


	A &_allocator;
	int _size;
	int _capacity;
public:

	Vector(size_type count = 0, A const &allocator = A());

	//	Capacity
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	void reserve(size_type value);
	size_type capacity() const;


	//	Element access
	reference at(size_type index);
	const_reference at(size_type index) const;

	reference operator[](size_type index);
	const_reference operator[](size_type index) const;

	reference front();
	const_reference front() const;

	reference back();
	const_reference back() const;

	pointer data();
	
	//	Iterators
	iterator begin();	
	const_iterator begin() const;	

	iterator end();	
	const_iterator end() const;	

	//	Modifiers
	void push_back(value_type item);
	void push_back(reference item);

	void pop_back();
};
/*
template<class T, class A>
Vector<T, A>::Vector(size_type count, T value, A const &allocator) : _allocator(const_cast<A&>(allocator)), _size(count), _capacity(count?count:8)
{
	_allocator.allocate(10);
}


//	Capacity
template<class T, class A>
bool Vector<T, A>::empty() const
{
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::size() const
{
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::max_size() const
{
}

template<class T, class A>
void Vector<T, A>::reserve(size_type value)
{
}

template<class T, class A>
typename Vector<T, A>::size_type Vector<T, A>::capacity() const
{
}


//	Element access
template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::at(size_type index)
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::at(size_type index) const
{
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::operator[](size_type index)
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::operator[](size_type index) const
{
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::front()
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::front() const
{
}

template<class T, class A>
typename Vector<T, A>::reference Vector<T, A>::back()
{
}

template<class T, class A>
typename Vector<T, A>::const_reference Vector<T, A>::back() const
{
}

template<class T, class A>
typename Vector<T, A>::pointer Vector<T, A>::data()
{
}
	
//	Iterators
template<class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::begin()
{
}

template<class T, class A>
typename Vector<T, A>::const_iterator Vector<T, A>::begin() const
{
}

template<class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::end()
{
}

template<class T, class A>
typename Vector<T, A>::const_iterator Vector<T, A>::end() const
{
}

//	Modifiers
template<class T, class A>
void Vector<T, A>::push_back(value_type item)
{
}

template<class T, class A>
void Vector<T, A>::push_back(reference item)
{
}

template<class T, class A>
void Vector<T, A>::pop_back()
{
}
*/
