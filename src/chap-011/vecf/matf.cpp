#include "matf_impl.h"

namespace Vec
{
	Matf::Matf(int rows, int cols)
	{
		for(int row_idx = 0; row_idx < rows; ++row_idx)
		{
			_value.push_back(Vecf(cols));
		}
	}

	Matf::Matf(std::vector<Vecf> value) : _value(value)
	{
	}

	int Matf::size() const
	{
		return _value.size();
	}

	int Matf::rows() const
	{
		return _value.size();
	}

	int Matf::cols() const
	{
		if(rows() == 0)
			return 0;
		else
			return _value[0].size();
	}

	Vecf &Matf::operator[](int index)
	{
		if(index >= size())
			throw Out_of_range_exception();

		return _value[index];
	}

	Matf &Matf::operator+=(Matf &mat)
	{
		validate_mat_size_equal(*this, mat);

		for(int row_idx = 0; row_idx < size(); ++row_idx)
			_value[row_idx] += mat[row_idx];

		return *this;
	}

	Matf &Matf::operator-=(Matf &mat)
	{
		validate_mat_size_equal(*this, mat);

		for(int row_idx = 0; row_idx < size(); ++row_idx)
			_value[row_idx] -= mat[row_idx];

		return *this;
	}

	Matf &Matf::operator*=(Matf &mat)
	{
		validate_mat_size_symmetric(*this, mat);

		Matf result = *this * mat;

		_value.clear();
		for(int row_idx = 0; row_idx < result.size(); ++row_idx)
			_value.push_back(result[row_idx]);

		return *this;
	}

	Matf &Matf::operator*=(float const scalar)
	{
		for(int row_idx = 0; row_idx < size(); ++row_idx)
			_value[row_idx] *= (float)scalar;

		return *this;
	}

	Matf operator+(Matf &mat1, Matf &mat2)
	{
		validate_mat_size_equal(mat1, mat2);

		Matf result = mat1;

		for(int row_idx = 0; row_idx < mat1.size(); ++row_idx)
			result[row_idx] += mat2[row_idx];

		return result;
	}
	Matf operator-(Matf &mat1, Matf &mat2)
	{
		validate_mat_size_equal(mat1, mat2);

		Matf result = mat1;

		for(int row_idx = 0; row_idx < mat1.size(); ++row_idx)
			result[row_idx] -= mat2[row_idx];

		return result;
	}
	Matf operator*(Matf &mat1, Matf &mat2)
	{
		validate_mat_size_symmetric(mat1, mat2);

		Matf result(mat1.size(), mat2[0].size());
		for(int row_idx = 0; row_idx < mat1.size(); ++row_idx)
		{
			for(int col_idx = 0; col_idx < mat2[0].size(); ++col_idx)
			{
				float value = 0.f;
				for(int k = 0; k < mat1[0].size(); ++k)
				{
					value += mat1[row_idx][k] * mat2[k][col_idx];
				}
				result[row_idx][col_idx] = value;
			}
		}

		return result;
	}

	Matf operator*(int const scalar, Matf const &mat)
	{
		Matf result = mat;

		for(int row_idx = 0; row_idx < mat.size(); ++row_idx)
			result[row_idx] *= scalar;

		return result;
	}

	bool operator==(Matf &mat1, Matf &mat2)
	{
		if(!mat_size_equal(mat1, mat2))
			return false;

		for(int row_idx = 0; row_idx < mat1.rows(); ++row_idx)
			if(mat1[row_idx] != mat2[row_idx])
				return false;

		return true;
	}

	bool operator!=(Matf &mat1, Matf &mat2)
	{
		return !(mat1 == mat2);
	}

	std::ostream& operator<<(std::ostream& stream, Matf &mat)
	{
		for(int row_idx = 0; row_idx < mat.size(); ++row_idx)
			stream << mat[row_idx] << std::endl;

		return stream;
	}
}
