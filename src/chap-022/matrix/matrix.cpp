#include <vector>
#include <cstdarg>
#include <numeric>
#include <ostream>
#include <iostream>
#include <valarray>
#include <iterator>

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

//template<class T>
//class MatrixIterator;

template<class T>
class Matrix
{
public:
	
	template<class U = T>
	class MatrixIterator : public std::iterator<std::input_iterator_tag, U>
	{
		Matrix<U> &_container;
		size_t _current;
	public:
		MatrixIterator(Matrix<U> &container, bool end = false);
		U& operator*();
		MatrixIterator &operator++();
		MatrixIterator operator++(int);

		bool operator==(MatrixIterator<U> const &other);
		bool operator!=(MatrixIterator<U> const &other);
		
	};
	
	typedef size_t size_type;
	typedef T value_type;
	typedef ptrdiff_t distance;
	
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & cont_reference;

	typedef MatrixIterator<T> iterator;
		
	
	std::vector<size_t> _dimensions;
	std::valarray<T> _va;

	size_t GetSize() const;
	size_t GetIndex(std::vector<size_t> dimension_indicies) const;
	
 public:
	Matrix(std::vector<size_t> dimensions);
	Matrix(std::vector<size_t> dimensions, std::valarray<T> va);

	std::vector<size_t> GetDimensions() const;

	MatrixIterator<T> begin();
	MatrixIterator<T> end();

	T& operator[](size_type index);
	T& operator()(std::vector<size_t> indicies);
	T& operator()(size_t firstIndex,...);

	template<class U>
	friend Matrix<U> operator+(Matrix<U> const &a, Matrix<U> const &b);

};

//Matrix iterator

template<class T>
template<class U>
Matrix<T>::MatrixIterator<U>::MatrixIterator(Matrix<U> &container, bool end)
	:_container(container), _current(end?container.GetSize():0)
{
	//std::cout << "size=" << container.GetSize() << std::endl;
}

template<class T>
template<class U>
U& Matrix<T>::MatrixIterator<U>::operator*()
{
	return _container[_current];
}

template<class T>
template<class U>
Matrix<T>::MatrixIterator<U> &Matrix<T>::MatrixIterator<U>::operator++()
{
	++_current;

	return *this;
}

template<class T>
template<class U>
Matrix<T>::MatrixIterator<U> Matrix<T>::MatrixIterator<U>::operator++(int)
{
	MatrixIterator<U> temp = *this;
	
	++_current;

	return temp;
}

template<class T>
template<class U>
bool Matrix<T>::MatrixIterator<U>::operator==(MatrixIterator const &other)
{
	return _current == other._current && &_container._va == &other._container._va;
}

template<class T>
template<class U>
bool Matrix<T>::MatrixIterator<U>::operator!=(MatrixIterator const &other)
{
	return !(*this == other);
}

//Matrix
template<class T>
Matrix<T>::Matrix(std::vector<size_t> dimensions)
	: _dimensions(dimensions), _va(GetSize())
{
}

template<class T>
Matrix<T>::Matrix(std::vector<size_t> dimensions, std::valarray<T> va)
	: _dimensions(dimensions), _va(va)
{
}

template<class T>
size_t Matrix<T>::GetSize() const
{
	return std::accumulate(_dimensions.begin(), _dimensions.end(), 1, std::multiplies<size_t>());
}

template<class T>
size_t Matrix<T>::GetIndex(std::vector<size_t> dimension_indicies) const
{
	size_t result = 0;
	
	for(size_t idx = 0; idx < dimension_indicies.size(); ++idx)
	{
		int dim_result = 1;
		for(size_t dim_idx = idx + 1; dim_idx < _dimensions.size(); ++dim_idx)
			dim_result *= _dimensions[idx];
		
		result += dimension_indicies[idx] * dim_result;
	}
	
	return result;
}

template<class T>
std::vector<size_t> Matrix<T>::GetDimensions() const
{
	return _dimensions;
}

template<class T>
typename Matrix<T>::iterator  Matrix<T>::begin()
{
	return MatrixIterator<T>(*this);
}

template<class T>
typename Matrix<T>::iterator Matrix<T>::end()
{
	return MatrixIterator<T>(*this, true);
}

template<class T>
T& Matrix<T>::operator[](size_type index)
{
	return _va[index];
}


template<class T>
T& Matrix<T>::operator()(std::vector<size_t> indicies)
{
	size_t index = GetIndex(indicies);
	//std::cout << index << std::endl;
	return _va[index];
}

template<class T>
T& Matrix<T>::operator()(size_t firstIndex,...)
{
	va_list vaList;
	
	std::vector<size_t> indiciesVec;
	int argsNumber = _dimensions.size();
	
	va_start(vaList, firstIndex);
	
	indiciesVec.push_back(firstIndex);
	
	for(int idx = 0; idx < argsNumber - 1; ++idx)
	{
		size_t dimension_index = va_arg(vaList, size_t);
		indiciesVec.push_back(dimension_index);
	}
	
	return this->operator()(indiciesVec);
}

template<class T>
Matrix<T> operator+(Matrix<T> const &a, Matrix<T> const &b)
{
	return Matrix<T>(a._dimensions, a._va + b._va);
}

template<class T>
std::ostream &operator<<(std::ostream &stream, Matrix<T> matrix)
{
	stream << "Matrix size: (";

	for(int idx_dim = 0; idx_dim < matrix.GetDimensions().size(); ++idx_dim)
	{
		if(idx_dim > 0)
			stream << ", ";
		
		stream << matrix.GetDimensions()[idx_dim];
	}

	stream << ");" << std::endl << "Values: (";

	for(typename Matrix<T>::iterator it = matrix.begin(); it != matrix.end(); ++it)
	{
		if(it != matrix.begin())
			stream << ", ";
		stream << *it;
	}

	stream << ")";
	   
	
	return stream;
}

int main()
{
	size_t const MX_COLS = 3;
	size_t const MX_ROWS = 3;
	size_t const MX_THRD_DIM = 3;
	
	Matrix<int>
		m1({MX_COLS, MX_ROWS, MX_THRD_DIM}),
		m2({MX_COLS, MX_ROWS, MX_THRD_DIM});
	
	for(int idx = 0; idx < MX_COLS; ++idx)
		for(int jdx = 0; jdx < MX_ROWS; ++jdx)
			for(int kdx = 0; kdx < MX_THRD_DIM; ++kdx)
			{
				m1(idx, jdx, kdx) = (idx + 1) * (jdx + 1) * (kdx + 1);
				m2(idx, jdx, kdx) = (idx + 1) + (jdx + 1) + (kdx + 1);
			}

	std::cout << "m1::" << m1 << std::endl;
	std::cout << "m2::" << m2 << std::endl;

	Matrix<int> m3 = m1 + m2;

	std::cout << "m3::" << m3 << std::endl;
	
	std::cout << "(2, 2, 2) = " << m1(2, 2, 2) << std::endl;


	return EXIT_SUCCESS;
}
