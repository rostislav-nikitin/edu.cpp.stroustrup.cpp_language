#include "mat4f.h"

int main()
{
	using Vec::Vec4f;
	using Vec::Mat4f;

	Mat4f empty_mat;
	std::cout << "Empty Mat4f: " << std::endl << empty_mat << std::endl;

	Mat4f mat1 = Mat4f({{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}});
	std::cout << "mat1: " << std::endl << mat1 << std::endl;

	Mat4f mat2 = Mat4f({{0,0,0,1},{0,0,1,0},{0,1,0,0},{1,0,0,0}});
	std::cout << "mat2: " << std::endl << mat2 << std::endl;

	Mat4f mat_add = mat1 + mat2;
	std::cout << "mat1 + mat2: " << std::endl << mat_add << std::endl;

	Mat4f mat_sub = mat1 - mat2;
	std::cout << "mat1 - mat2: " << std::endl << mat_sub << std::endl;

	Mat4f mat_smul = 10.f * mat1;
	std::cout << "10.f * mat1: " << std::endl << mat_smul << std::endl;


	Mat4f mat_one = Mat4f({{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}});
	std::cout << "mat_one: " << std::endl << mat_one << std::endl;

	Mat4f mat_mul = mat_one * mat_one;
	std::cout << "mat_one * mat_one: " << std::endl << mat_mul << std::endl;

	return 0;
}
