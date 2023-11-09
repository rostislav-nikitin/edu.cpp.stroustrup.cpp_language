#include "vecf_helpers.h"

namespace Vec
{
	void validate_vecs_size(Vecf const &vec1, Vecf const &vec2)
	{
		if(vec1.size() != vec2.size())
			throw Uncompartible_size_exception();
	}
}
