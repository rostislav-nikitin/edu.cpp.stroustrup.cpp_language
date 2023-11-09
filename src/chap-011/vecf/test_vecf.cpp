#include "vecf_abstractions.h"

int main()
{
	using Vec::Vecf;

	Vecf vec1 = Vecf(4);
	vec1[0] = 1.f;
	vec1[1] = 2.f;
	vec1[2] = 3.f;
	vec1[3] = 4.f;
	std::cout << "vec1: " << vec1 << std::endl;

	Vecf vec2 = Vecf({10.f, 20.f, 30.f, 40.f});
	std::cout << "vec2: " << vec2 << std::endl;

	std::cout << "vec1 == vec1: " << (vec1 == vec1) << std::endl;
	std::cout << "vec1 != vec1: " << (vec1 != vec1) << std::endl;
	std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl;
	std::cout << "vec1 != vec2: " << (vec1 != vec2) << std::endl;

	Vecf vec_sum = vec1 + vec2;
	std::cout << "vec1 + vec2: " << vec_sum << std::endl;

	Vecf vec_sub = vec2 - vec1;
	std::cout << "vec2 - vec1: " << vec_sub << std::endl;

	Vecf vec_smul = 10.f * vec2;
	std::cout << "10.f * vec2: " << vec_smul << std::endl;

	try
	{
		float x = vec1[5];
	}
	catch(Vec::Out_of_range_exception ex)
	{
		std::cout << "[Expected] Out of range exception" << std::endl;
	}

	Vecf vec3 = Vecf({1.f, 2.f, 3.f, 4.f, 5.f});
	std::cout << "vec1 == vec3: " << (vec1 == vec3) << std::endl;
	try
	{
		vec1 + vec3;
	}
	catch(Vec::Uncompartible_size_exception ex)
	{
		std::cout << "[Expected] Uncompartible size exception" << std::endl;
	}

	vec1 += vec1;
	std::cout << "vec1 += vec1: " << vec1 << std::endl;

	vec2 -= vec1;
	std::cout << "vec2 -= vec1: " << vec2 << std::endl;

	vec1 *= 10.f;
	std::cout << "vec1 *= vec1: " << vec1 << std::endl;

	return 0;
}
