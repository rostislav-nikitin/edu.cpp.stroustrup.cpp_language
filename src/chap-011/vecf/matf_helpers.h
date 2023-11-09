#ifndef MATF_HELPERS_H
#define MATF_HELPERS_H

#include "matf_abstractions.h"

namespace Vec
{
	bool mat_size_equal(Matf const &mat1, Matf const &mat2);
	bool mat_size_symmetric(Matf const &mat1, Matf const &mat2);

	void validate_mat_size_equal(Matf const &mat1, Matf const &mat2);
	void validate_mat_size_symmetric(Matf const &mat1, Matf const &mat2);
	void validate_mat_size_equal_or_symmetric(Matf const &mat1, Matf const &mat2);
}

#endif
