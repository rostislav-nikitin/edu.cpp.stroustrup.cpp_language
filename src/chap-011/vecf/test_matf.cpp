#include "matf_abstractions.h"

int main()
{
	using Vec::Matf;
	using Vec::Vecf;

	Matf mat1 = Matf(
		{
			Vecf({1, 0, 0, 0}), 
			Vecf({0, 1, 0, 0}), 
			Vecf({0, 0, 1, 0}), 
			Vecf({0, 0, 0, 1})
		});
	std::cout << "mat1: " << std::endl << mat1 << std::endl;

	Matf mat2 = Matf(
		{
			Vecf({0, 0, 0, 1}), 
			Vecf({0, 0, 1, 0}), 
			Vecf({0, 1, 0, 0}), 
			Vecf({1, 0, 0, 0})
		});
	std::cout << "mat2: " << std::endl << mat2 << std::endl;

	std::cout << "mat1==mat1: " << (mat1 == mat1) << std::endl;
	std::cout << "mat1!=mat1: " << (mat1 != mat1) << std::endl;
	std::cout << "mat1==mat2: " << (mat1 == mat2) << std::endl;
	std::cout << "mat1!=mat2: " << (mat1 != mat2) << std::endl;

	Matf mat_add = mat1 + mat2;
	std::cout << "mat1 + mat2: " << std::endl << mat_add << std::endl;

	Matf mat_sub = mat1 - mat2;
	std::cout << "mat1 - mat2: " << std::endl << mat_sub << std::endl;

	Matf mat2x3 = Matf(
		{
			Vecf({1, 1, 1}), 
			Vecf({1, 1, 1}) 
		});
	std::cout << "mat2x3: " << std::endl << mat2x3 << std::endl;

	Matf mat3x2 = Matf(
		{
			Vecf({1, 1}), 
			Vecf({1, 1}),
			Vecf({1, 1}) 
		});

	std::cout << "mat2x3==mat3x2: " << (mat2x3 == mat3x2) << std::endl;

	std::cout << "mat3x2: " << std::endl << mat3x2 << std::endl;

	Matf mat_mul = mat2x3 * mat3x2;
	std::cout << "mat2x3 * mat3x2: " << std::endl << mat_mul << std::endl;

	Matf mat4x4 = Matf(
		{
			Vecf({1, 1, 1, 1}), 
			Vecf({1, 1, 1, 1}), 
			Vecf({1, 1, 1, 1}), 
			Vecf({1, 1, 1, 1})
		});

	Matf mat_sqr = mat4x4 * mat4x4;
	std::cout << "mat4x4 * mat4x4: " << std::endl << mat_sqr << std::endl;

	Matf mat_smul = 10.f * mat1;
	std::cout << "10.f * mat1: " << std::endl << mat_smul << std::endl;

	try
	{
		mat1[10];
	}
	catch(Vec::Out_of_range_exception ex)
	{
		std::cout << "[Expected] mat1[10]: Out of range exception" << std::endl;
	}

	try
	{
		mat1[0][10];
	}
	catch(Vec::Out_of_range_exception ex)
	{
		std::cout << "[Expected] mat1[0][10]: Out of range exception" << std::endl;
	}

	try
	{
		mat2x3 + mat3x2;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] mat2x3 + mat3x2: Uncompartible size exception" << std::endl;
	}

	try
	{
		mat2x3 - mat3x2;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] mat2x3 - mat3x2: Uncompartible size exception" << std::endl;
	}
	try
	{
		mat2x3 * mat4x4;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] mat2x3 * mat4x4: Uncompartible size exception" << std::endl;
	}


	try
	{
		mat2x3 += mat3x2;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] mat2x3 += mat3x2: Uncompartible size exception" << std::endl;
	}
	try
	{
		mat2x3 -= mat3x2;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] mat2x3 -= mat3x2: Uncompartible size exception" << std::endl;
	}
	try
	{
		mat2x3 *= mat4x4;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] mat2x3 *= mat4x4: Uncompartible size exception" << std::endl;
	}

	std::cout << "mat2x3 *= mat3x2: " << std::endl << (mat2x3 *= mat3x2) << std::endl;
	std::cout << "mat2x2 += mat2x2: " << std::endl << (mat2x3 += mat2x3) << std::endl;
	std::cout << "mat2x2 *= 10.f: " << std::endl << (mat2x3 *= 10.f) << std::endl;
	std::cout << "mat2x2 -= mat2x2: " << std::endl << (mat2x3 -= mat2x3) << std::endl;

	return 0;
}
