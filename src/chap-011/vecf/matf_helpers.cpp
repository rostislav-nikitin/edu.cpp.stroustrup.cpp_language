#include "matf_helpers.h"

namespace Vec
{
	bool mat_size_equal(Matf const &mat1, Matf const &mat2)
	{
		return mat1.rows() == mat2.rows() && mat1.cols() == mat2.cols();
	}

	bool mat_size_symmetric(Matf const &mat1, Matf const &mat2)
	{
		return mat1.rows() == mat2.cols() && mat1.cols() == mat2.rows();
	}

	void validate_mat_size_equal(Matf const &mat1, Matf const &mat2)
	{
		if(!mat_size_equal(mat1, mat2))
			throw Uncompartible_size_exception();
	}

	void validate_mat_size_symmetric(Matf const &mat1, Matf const &mat2)
	{
		if(!mat_size_symmetric(mat1, mat2))
			throw Uncompartible_size_exception();
	}

	void validate_mat_size_equal_or_symmetric(Matf const &mat1, Matf const &mat2)
	{
		if(!mat_size_equal(mat1, mat2) && !mat_size_symmetric(mat1, mat2))
			throw Uncompartible_size_exception();
	}
}
