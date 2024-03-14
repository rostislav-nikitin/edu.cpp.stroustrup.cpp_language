#include <valarray>

#include <iostream>

// Row iter
template<class T>
class Slice_row_iter
{
	std::valarray<T> _va;
	std::slice _slice;

	size_t _current;
public:
	Slice_row_iter(std::valarray<T> &va, std::slice slice, bool end = false);
	Slice_row_iter(std::valarray<T> &va, size_t start, size_t size, size_t stride, bool end = false);

	std::valarray<T> operator*();
	//T operator*() const;

	Slice_row_iter &operator++();
	Slice_row_iter operator++(int);

	bool operator==(Slice_row_iter const &value);
	bool operator!=(Slice_row_iter const &value);
	
};

template<class T>
Slice_row_iter<T>::Slice_row_iter(std::valarray<T> &va, std::slice slice, bool end)
	: _va(va), _slice(slice), _current(end?slice.size():slice.start())
{
}

template<class T>
Slice_row_iter<T>::Slice_row_iter(std::valarray<T> &va, size_t start, size_t size, size_t stride, bool end)
	: _va(va), _slice(start, size, stride), _current(end?size:start)
{
}

template<class T>
std::valarray<T> Slice_row_iter<T>::operator*()
{
	//	std::slice s(_slice.start(), ,  _slice.stride());
	
	return _va[std::slice(_current * _slice.size(), _slice.size(), _slice.stride())];
}
/*
template<class T>
T Slice_row_iter<T>::operator*() const
{
	return _va[_slice.start() + _current * _slice.stride()];
}
*/
template<class T>
Slice_row_iter<T> &Slice_row_iter<T>::operator++()
{
	++_current;
	
	return *this;
}

template<class T>
Slice_row_iter<T> Slice_row_iter<T>::operator++(int)
{
	Slice_row_iter temp = *this;
	++_current;

	return temp;
}

template<class T>
bool Slice_row_iter<T>::operator==(Slice_row_iter<T> const &value)
{
	return _current == value._current
		&& _slice.size() == value._slice.size()
		&& _slice.stride() == value._slice.stride();
}

template<class T>
bool Slice_row_iter<T>::operator!=(Slice_row_iter<T> const &value)
{
	return !(*this == value);
}

// Column iter
template<class T>
class Slice_column_iter
{
	std::valarray<T> _va;
	std::slice _slice;

	size_t _current;
public:
	Slice_column_iter(std::valarray<T> &va, std::slice slice, bool end = false);
	Slice_column_iter(std::valarray<T> &va, size_t start, size_t size, size_t stride, bool end = false);

	std::valarray<T> operator*();
	//T operator*() const;

	Slice_column_iter &operator++();
	Slice_column_iter operator++(int);

	bool operator==(Slice_column_iter const &value);
	bool operator!=(Slice_column_iter const &value);
	
};

template<class T>
Slice_column_iter<T>::Slice_column_iter(std::valarray<T> &va, std::slice slice, bool end)
	: _va(va), _slice(slice), _current(end?slice.size():slice.start())
{
}

template<class T>
Slice_column_iter<T>::Slice_column_iter(std::valarray<T> &va, size_t start, size_t size, size_t stride, bool end)
	: _va(va), _slice(start, size, stride), _current(end?size:start)
{
}

template<class T>
std::valarray<T> Slice_column_iter<T>::operator*()
{
	//	std::slice s(_slice.start(), ,  _slice.stride());
	
	return _va[std::slice(_current, _slice.size(), _slice.stride())];
}
/*
template<class T>
T Slice_column_iter<T>::operator*() const
{
	return _va[_slice.start() + _current * _slice.stride()];
}
*/
template<class T>
Slice_column_iter<T> &Slice_column_iter<T>::operator++()
{
	++_current;
	
	return *this;
}

template<class T>
Slice_column_iter<T> Slice_column_iter<T>::operator++(int)
{
	Slice_column_iter temp = *this;
	++_current;

	return temp;
}

template<class T>
bool Slice_column_iter<T>::operator==(Slice_column_iter<T> const &value)
{
	return _current == value._current
		&& _slice.size() == value._slice.size()
		&& _slice.stride() == value._slice.stride();
}

template<class T>
bool Slice_column_iter<T>::operator!=(Slice_column_iter<T> const &value)
{
	return !(*this == value);
}


template<class T>
std::ostream &operator<<(std::ostream &stream, std::valarray<T> const &va)
{
	for(size_t idx = 0; idx < va.size(); ++idx)
	{
		if(idx > 0)
			stream << ", ";
		
		stream << va[idx];
	}

	return stream;
}


int main()
{
	// M:3x3
	int v[9] {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::valarray<int> va(v, 9);
	std::cout << va << std::endl;

	std::cout << "Rows: " << std::endl;
	Slice_row_iter<int> it_row_begin(va, 0, 3, 1, false);
	Slice_row_iter<int> it_row_end(va, 0, 3, 1, true);
	
	while(it_row_begin != it_row_end)
	{
		std::cout << *it_row_begin << std::endl;
		++it_row_begin;
	}

	std::cout << "Columns: " << std::endl;		
	Slice_column_iter<int> it_column_begin(va, 0, 3, 3, false);
	Slice_column_iter<int> it_column_end(va, 0, 3, 3, true);
	
	while(it_column_begin != it_column_end)
	{
		std::cout << *it_column_begin << std::endl;
		++it_column_begin;
	}
	
	return EXIT_SUCCESS;
}
