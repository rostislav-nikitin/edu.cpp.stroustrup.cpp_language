#include "vec4f.h"

namespace Vec
{

	Vec4f::Cell::Cell(Vec4f &vec, int index) : _value(vec), _index(index)
	{
	}

	Vec4f::Cell::operator float() const
	{
//		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return _value._value[_index];
	}

	float Vec4f::Cell::operator=(float value)
	{
		_value._value[_index] = value;

		return _value._value[_index];
	}

	float Vec4f::Cell::operator+=(float value)
	{
		_value._value[_index] += value;

		return _value._value[_index];
	}

	float Vec4f::Cell::operator-=(float value)
	{
		_value._value[_index] -= value;

		return _value._value[_index];
	}

	Vec4f &Vec4f::Cell::operator=(Cell const &cell)
	{
		_value._value[_index] = cell;

		return _value;
	}

	Vec4f::Vec4f() : _value {0.f, 0.f, 0.f, 0.f}
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Vec4f::Vec4f(float a, float b, float c, float d) : _value{a, b, c, d}
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Vec4f::Vec4f(Vec4f const &vec)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		copy(vec);
	}
	Vec4f::Vec4f(Vec4f &vec)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		copy(vec);
	}
	void Vec4f::copy(Vec4f const &vec)
	{
		for(int idx = 0; idx < 4; ++idx)
			_value[idx] = vec._value[idx];
	}

	float Vec4f::operator[](int const index) const
	{
		return _value[index];
	}

	Vec4f::Cell Vec4f::operator[](int const index)
	{
		if(index < 0 || index > 3)
			throw Out_of_range_exception();

		return Cell(*this, index);
	}

	Vec4f Vec4f::operator=(Vec4f &vec)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		copy(vec);

		return *this;
	}

	Vec4f Vec4f::operator=(Vec4f const &vec)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		copy(vec);

		return *this;
	}

	Vec4f &Vec4f::operator+=(Vec4f const &vec)
	{
	
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		for(int idx = 0; idx < 4; ++idx)
			_value[idx] += vec._value[idx];

		return *this;
	}

	Vec4f &Vec4f::operator-=(Vec4f const &vec)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		for(int idx = 0; idx < 4; ++idx)
			_value[idx] -= vec._value[idx];

		return *this;
	}

	Vec4f &Vec4f::operator*=(float const s)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		for(int idx = 0; idx < 4; ++idx)
			_value[idx] *= s;

		return *this;
	}

	Vec4f &Vec4f::operator/=(float const s)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		for(int idx = 0; idx < 4; ++idx)
			_value[idx] /= s;

		return *this;
	}

	Vec4f operator+(Vec4f const &vec1, Vec4f const &vec2)
	{
		Vec4f result = vec1;

		for(int idx = 0; idx < 4; ++idx)
			result._value[idx] += vec2._value[idx];

		return result;
	}

	Vec4f operator-(Vec4f const &vec1, Vec4f const &vec2)
	{
		Vec4f result = vec1;

		for(int idx = 0; idx < 4; ++idx)
			result._value[idx] -= vec2._value[idx];

		return result;
	}

	Vec4f operator*(float const s, Vec4f const &vec)
	{
		Vec4f result = vec;

		for(int idx = 0; idx < 4; ++idx)
			result._value[idx] *= s;

		return result;
	}
	Vec4f operator/(Vec4f const &vec, float const s)
	{
		Vec4f result = vec;

		for(int idx = 0; idx < 4; ++idx)
			result._value[idx] /= s;

		return result;
	}

	std::ostream& operator<<(std::ostream &stream, Vec4f const &vec)
	{
		stream << "[" << vec._value[0] << ", " <<  vec._value[1] << ", " << vec._value[2] << ", " << vec._value[3] << "]";

		return stream;
	}
}
