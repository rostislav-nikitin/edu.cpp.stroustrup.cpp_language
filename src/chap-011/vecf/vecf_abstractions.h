#ifndef VECF_ABSTRACTIONS_H
#define VECF_ABSTRACTIONS_H

#include <iostream>
#include <vector>

#include "vec_abstractions.h"

namespace Vec
{
	class Vecf
	{
	private:
		class Cell
		{
		private:
			Vecf &_value;
			int _index;
		public:
			Cell(Vecf &value, int index);

			operator float();
			float operator=(float value);
		};

		std::vector<float> _value;

		void validate_index(int const index) const;
	public:
		explicit Vecf(int size);
		Vecf(std::vector<float> const &vec);

		int size() const;

		float operator[](int index) const;
		Cell operator[](int index);

		Vecf &operator+=(Vecf const &vec);
		Vecf &operator-=(Vecf const &vec);
		Vecf &operator*=(float const scalar);

		friend std::ostream& operator<<(std::ostream &stream, Vecf &vec);
	};
	Vecf operator+(Vecf const &vec1, Vecf const &vec2);
	Vecf operator-(Vecf const &vec1, Vecf const &vec2);
	Vecf operator*(int const scalar, Vecf const &vec);

	bool operator==(Vecf const &vec1, Vecf const &vec2);
	bool operator!=(Vecf const &vec1, Vecf const &vec2);
}

#endif
