#include <iostream>

namespace Vec
{
	class Vec4f
	{
	private:
		class Cell
		{
		private:
			Vec4f &_value;
			int _index;

		public:
			Cell(Vec4f &vec, int index);

			float operator=(float const);
			float operator+=(float const);
			float operator-=(float const);
			Vec4f &operator=(Vec::Vec4f::Cell const&);
			operator float() const;
		};

		float _value[4];

		void copy(Vec4f const &vec);
	public:
		class Out_of_range_exception { };

		Vec4f();
		Vec4f(float a, float b, float c, float d);
		Vec4f(Vec4f const &vec);
		Vec4f(Vec4f &vec);

		Cell operator[](int const index);
		float operator[](int const index) const;
		Vec4f operator=(Vec4f &vec);
		Vec4f operator=(Vec4f const &vec);
		Vec4f &operator+=(Vec4f const &vec);
		Vec4f &operator-=(Vec4f const &vec);
		Vec4f &operator*=(float const s);
		Vec4f &operator/=(float const s);

		friend Vec4f operator+(Vec4f const &vec1, Vec4f const &vec2);
		friend Vec4f operator-(Vec4f const &vec1, Vec4f const &vec2);
		friend Vec4f operator*(float const s, Vec4f const &vec);
		friend Vec4f operator/(Vec4f const &vec, float const s);

		friend std::ostream& operator<<(std::ostream &stream, Vec4f const &vec);
	};

}
