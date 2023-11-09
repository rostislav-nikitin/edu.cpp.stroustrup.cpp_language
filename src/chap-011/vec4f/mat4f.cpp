#include "mat4f.h"

namespace Vec
{
	Mat4f::Mat4f() : _value{Vec4f(), Vec4f(), Vec4f(), Vec4f()} 
	{
	}

	Mat4f::Mat4f(Vec4f const mat[4])
	{
		for(int row_idx = 0; row_idx < 4; ++row_idx)
			_value[row_idx] = Vec4f(mat[row_idx]);
	}

	Mat4f::Mat4f(Vec4f const &vec1, Vec4f const &vec2, Vec4f const &vec3, Vec4f const &vec4)
	{
		_value[0] = Vec4f(vec1);
		_value[1] = Vec4f(vec2);
		_value[2] = Vec4f(vec3);
		_value[3] = Vec4f(vec4);
	}

	Mat4f &Mat4f::operator=(Mat4f &mat)
	{
		copy(mat);

		return *this;
	}

	Mat4f &Mat4f::operator=(Mat4f const &mat)
	{
		copy(mat);

		return *this;
	}

	void Mat4f::copy(Mat4f const &mat)
	{
		for(int row_idx = 0; row_idx < 4; ++row_idx)
			_value[row_idx] = Vec4f(mat._value[row_idx]);
	}

	Vec4f &Mat4f::operator[](int index)
	{
		return _value[index];
	}

	//Vec4f &operator[](int index);

	Mat4f operator+(Mat4f &mat1, Mat4f &mat2)
	{
		Mat4f result = mat1;

		for(int row_idx = 0; row_idx < 4; ++row_idx)
		{
			for(int col_idx = 0; col_idx < 4; ++col_idx)
			{
				result[row_idx][col_idx] += mat2[row_idx][col_idx];
			}
		}
	
		return result;
	}

	Mat4f operator-(Mat4f &mat1, Mat4f &mat2)
	{
		Mat4f result = mat1;

		for(int row_idx = 0; row_idx < 4; ++row_idx)
		{
			for(int col_idx = 0; col_idx < 4; ++col_idx)
			{
				result[row_idx][col_idx] -= mat2[row_idx][col_idx];
			}
		}
	
		return result;
	}

	Mat4f operator*(Mat4f &mat1, Mat4f &mat2)
	{
		Mat4f result;

		for(int row_idx = 0; row_idx < 4; ++row_idx)
		{
			for(int col_idx = 0; col_idx < 4; ++col_idx)
			{
				float value = 0.f;

				for(int k = 0; k < 4; ++k)
				{
					float x = mat1[row_idx][k];
					float y = mat2[k][col_idx];

					value += x * y;
				}

				result[row_idx][col_idx] = value;
			}
		}

		return result;
	}
	
	Mat4f operator*(float scalar, Mat4f const &mat)
	{
		Mat4f result(mat);

		for(int row_idx = 0; row_idx < 4; ++row_idx)
		{
			for(int col_idx = 0; col_idx < 4; ++col_idx)
			{
				float value = result[row_idx][col_idx];
				value *= scalar;
				result[row_idx][col_idx] = value;
			}
		}

		return result;
	}

	std::ostream& operator<<(std::ostream& stream, Mat4f const &mat)
	{
		for(int row_idx = 0; row_idx < 4; ++row_idx)
			stream << mat._value[row_idx] << std::endl;

		return stream;
	}
}
