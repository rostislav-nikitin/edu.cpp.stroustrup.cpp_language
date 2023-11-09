#include "vecf_impl.h"

namespace Vec
{
	Vecf::Cell::Cell(Vecf &value, int index) : _value(value), _index(index)
	{
	}

	Vecf::Cell::operator float()
	{
		return _value._value[_index];
	}
	float Vecf::Cell::operator=(float value)
	{
		_value._value[_index] = value;

		return value;
	}

	Vecf::Vecf(int size) : _value(size) 
	{ 
	}

	Vecf::Vecf(std::vector<float> const &vec) : _value(vec)
	{
	}

	int Vecf::size() const
	{
		return _value.size();
	}

	float Vecf::operator[](int index) const
	{
		validate_index(index);

		return _value[index];
	}

	Vecf::Cell Vecf::operator[](int index)
	{
		validate_index(index);

		return Cell(*this, index);
	}

	Vecf &Vecf::operator+=(Vecf const &vec)
	{
		validate_vecs_size(*this, vec);

		for(int idx = 0; idx < size(); ++idx)
			_value[idx] += vec[idx];

		return *this;
	}

	Vecf &Vecf::operator-=(Vecf const &vec)
	{
		validate_vecs_size(*this, vec);

		for(int idx = 0; idx < size(); ++idx)
			_value[idx] -= vec[idx];

		return *this;
	}

	Vecf &Vecf::operator*=(float const scalar)
	{
		for(int idx = 0; idx < size(); ++idx)
			_value[idx] *= scalar;

		return *this;
	}

	std::ostream& operator<<(std::ostream &stream, Vecf &vec)
	{
		std::cout << "[";
		for(int idx = 0; idx < vec._value.size(); ++idx)
		{
			std::cout << ((idx == 0) ? "" : ", ") << vec._value[idx];
		}
		std::cout << "]";

		return stream;
	}


	Vecf operator+(Vecf const &vec1, Vecf const &vec2)
	{
		validate_vecs_size(vec1, vec2);

		Vecf result(vec1.size());
		
		for(int idx = 0; idx < vec1.size(); ++idx)
		{
			result[idx] = vec1[idx] + vec2[idx];
		}

		return result;
	}

	Vecf operator-(Vecf const &vec1, Vecf const &vec2)
	{
		validate_vecs_size(vec1, vec2);

		Vecf result(vec1.size());

		for(int idx = 0; idx < vec1.size(); ++idx)
		{
			result[idx] = vec1[idx] - vec2[idx];
		}

		return result;
	}
	Vecf operator*(int const scalar, Vecf const &vec)
	{
		Vecf result(vec.size());

		for(int idx = 0; idx < vec.size(); ++idx)
		{
			result[idx] = scalar * vec[idx];
		}

		return result;
	}

	bool operator==(Vecf const &vec1, Vecf const &vec2)
	{
		if(vec1.size() != vec2.size())
			return false;
		for(int row_idx = 0; row_idx < vec1.size(); ++row_idx)
			if(vec1[row_idx] != (float) vec2[row_idx])
				return false;

		return true;
	}

	bool operator!=(Vecf const &vec1, Vecf const &vec2)
	{
		return !(vec1 == vec2);
	}

	void Vecf::validate_index(int const index) const
	{
		if(index >= size())
			throw Out_of_range_exception();
	}
}
