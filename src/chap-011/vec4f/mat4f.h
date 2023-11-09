#include <iostream>

#include "vec4f.h"

namespace Vec
{
	class Mat4f
	{
	private:
		Vec4f _value[4];

		void copy(Mat4f const &mat);
	public:
		Mat4f();
		Mat4f(Vec4f const *);
		Mat4f(Vec4f const &vec1, Vec4f const &vec2, Vec4f const &vec3, Vec4f const &vec4);

		Mat4f &operator=(Mat4f &mat);
		Mat4f &operator=(Mat4f const &mat);

		Vec4f &operator[](int index);
		
		friend std::ostream& operator<<(std::ostream& stream, Mat4f const &mat);
	};

	Mat4f operator+(Mat4f &, Mat4f &);
	Mat4f operator-(Mat4f &, Mat4f &);
	Mat4f operator*(Mat4f &, Mat4f &);

	Mat4f operator*(float scalar, Mat4f const & mat);
}
