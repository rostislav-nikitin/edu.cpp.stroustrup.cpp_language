#include <iostream>
#include "vec4f.h"

int main()
{
	using Vec::Vec4f;

	Vec4f vec1(10, 20, 30, 40);
	std::cout << vec1 << std::endl;
	
	Vec4f vec2(15, 25, 35, 45);
	std::cout << vec2 << std::endl;

	Vec4f vec_add = vec1 + vec2;
	std::cout << "vec1 + vec2: " << vec_add << std::endl;

	Vec4f vec_sub = vec2 - vec1;
	std::cout << "vec2 - vec1: " << vec_sub << std::endl;

	Vec4f vec_mul = 10.f * vec1;
	std::cout << "10.f * vec2: " << vec_mul << std::endl;

	Vec4f vec_div = vec1 / 10.f;
	std::cout << "vec1 /10.f: " << vec_div << std::endl;


	Vec4f vec_assign = vec1;
	std::cout << "vec_assign = vec1: " << vec_assign << std::endl;

	Vec4f &x = (Vec4f() += vec1);
/*
	Vec4f &vec_assign_add = (Vec4f() += vec1);
	vec_assign_add *= 10;
	std::cout << "Vec4f() += vec1: " << vec_assign_add << std::endl;
	int const &x = int(10);
*/
	return 0;
}
