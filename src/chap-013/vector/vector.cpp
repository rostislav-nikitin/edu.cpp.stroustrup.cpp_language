#include <cstring>
#include <string>
#include <iostream>

template<class T, int initial_size = 10>
class Vector;

template<class T, int initial_size>
class Vector
{
private:
	T *_values = new T[initial_size];
	unsigned int _size = initial_size;
	unsigned int _next_index = 0;
public:
	void push_back(T const value);

	unsigned int size() const;
	T const operator[](int const index) const;
	T& operator[](int index);

	virtual ~Vector();
};

template<class T, int initial_size>
void Vector<T, initial_size>::push_back(T const value)
{
	if(_next_index >= _size)
	{
		unsigned int new_size = _size * 2;

		T* values = new T[new_size];
		for(int idx = 0; idx < _next_index; ++idx)
		{
			values[idx] = _values[idx];
		}

		delete[] _values;
		_values = values;
		_size = new_size;
		
		std::cout << "array resized. new size=" << _size << std::endl;
	}
	_values[_next_index++] = value;
		std::cout << "array resized. new size=" << _size << std::endl;
}


template<class T, int initial_size>
unsigned int Vector<T, initial_size>::size() const
{
	return _next_index;
}
template<class T, int initial_size>
T const Vector<T, initial_size>::operator[](int const index) const
{
	return _values[index];
}

template<class T, int initial_size>
T& Vector<T, initial_size>::operator[](int index)
{
	return _values[index];	
}

template<class T, int initial_size>
Vector<T, initial_size>::~Vector()
{
	delete[] _values;
}

template<class T>
void print_all(Vector<T> &values)
{
	for(int idx = 0; idx < values.size(); ++idx)
	{
		std::cout << values[idx] << std::endl;
	}
}

template<class T, int initial_size>
class Vector<T*, initial_size>;


template<int initial_size>
class Vector<void *, initial_size>;

//
template<int initial_size>
class Vector<void *, initial_size>
{
protected:
	unsigned int _size = initial_size;
	unsigned int _next_index = 0;
	void **_values;
public:
	Vector();
	void push_back(void *value);

	unsigned int size() const;

	void const* operator[](int const index) const;
	void*& operator[](int index);
	

	virtual ~Vector();

};

template<int initial_size>
Vector<void *, initial_size>::Vector() : _values(reinterpret_cast<void **>(::operator new[](sizeof(void *) * initial_size)))
{
}

template<int initial_size>
void Vector<void *, initial_size>::push_back(void *value)
{
	_values[_next_index++] = value;
};

template<int initial_size>
unsigned int Vector<void *, initial_size>::size() const
{
	return _next_index;
}


template<int initial_size>
void const * Vector<void *, initial_size>::operator[](int const index) const
{
	return _values[index];
}

template<int initial_size>
void*& Vector<void *, initial_size>::operator[](int index)
{
	return _values[index];
}

template<int initial_size>
Vector<void *, initial_size>::~Vector()
{
	delete[] _values;
}

//
template<class T, int initial_size>
class Vector<T*, initial_size> : private Vector<void*, initial_size>
{
private:
	typedef Vector<void *, initial_size> VectorBase;
	typedef Vector<T *, initial_size> VectorSelf;
	struct TRef
	{
	private:
		VectorSelf &_vector;
		unsigned int _index;
	public:
		TRef(VectorSelf &vector, unsigned int index) : _vector(vector), _index(index)
		{
		}

		TRef& operator=(T *value)
		{
			delete reinterpret_cast<T *>(_vector._values[_index]);
			_vector._values[_index] = value;

			return *this;			
		}

		operator T *()
		{
			return reinterpret_cast<T *>( _vector._values[_index]);
		}

	};
public:
	Vector();
	void push_back(T *value);

	unsigned int size() const;

	TRef get(int index)
	{
		return TRef(*this, index);
	}

	T const * operator[](int const index) const;
	T*& operator[](int index);
	

	virtual ~Vector();
};

template<class T, int initial_size>
Vector<T* ,initial_size>::Vector() : VectorBase()
{
}

template<class T, int initial_size>
void Vector<T *,initial_size>::push_back(T *value)
{
	VectorBase::push_back(value);
}

template<class T, int initial_size>
unsigned int Vector<T*, initial_size>::size() const
{
	return VectorBase::size();
}

template<class T, int initial_size>
T const * Vector<T*, initial_size>::operator[](int const index) const
{
	return reinterpret_cast<T const *>(VectorBase::operator[](index));
}

template<class T, int initial_size>
T*& Vector<T*, initial_size>::operator[](int index)
{
	return reinterpret_cast<T*&>(VectorBase::operator[](index));
}

template<class T, int initial_size>
Vector<T*, initial_size>::~Vector()
{
	for(int idx = 0; idx < VectorBase::size(); ++idx)
	{
		delete reinterpret_cast<T * const>(VectorBase::operator[](idx));
	}
}

class A
{
public:
	A()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A(A &a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A(A const &a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A(A &&a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	A& operator=(A &a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	A& operator=(A const &a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	A& operator=(A &&a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return *this;
	}
	A&& operator+(A &a)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return A(a);
	}
	virtual ~A()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

};

std::ostream& operator<<(std::ostream &stream, A *value)
{
	stream << "A address=" << (void *)value << std::endl;

	return stream;
}


std::ostream& operator<<(std::ostream &stream, A const *value)
{
	stream << "A address=" << (void *)value << std::endl;

	return stream;
}



template<class T>
void f(T t)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void g(A &a)
{
	A temp(std::move(a));
	A a2;
	a = std::move(a2);
	a2 = std::move(temp);

	A a3 = a + a2;

	//f(std::move(a));
	//f(std::move(a));
}

int main()
{
	Vector<std::string> svalues;
	svalues.push_back("Test1");
	svalues.push_back("Test2");
	svalues.push_back("Test3");

	for(int idx = 0; idx < 18; ++idx)
	{
		svalues.push_back("TTTTT");
	}


	print_all(svalues);
	svalues[1] = "FFF";
	std::cout << svalues[1] << std::endl;
/*
	std::cout << svalues[0] << std::endl;
	svalues[0] = "FFF";
	std::cout << svalues[0] << std::endl;
*/

	Vector<void *> vvalues;
	//A *a = new A();
	//vvalues.push_back(a);
	
	Vector<A *> avalues;
	A *a = new A();
	A *a2 = new A();
	A *a3 = new A();
	avalues.push_back(a);
	avalues.push_back(a2);
	avalues.get(1) = a3;
	std::cout << avalues.get(1) << std::endl;

	print_all(avalues);
	
//	std::cout << "Type=" << f(1)  << std::endl;

	g(*a3);

	return 0;
}
