#ifndef MATF_ABSTRACTIONS_H
#define MATF_ABSTRACTIONS_H

#include <iostream>
#include <vector>
#include "vecf_abstractions.h"

namespace Vec
{
	class Matf
	{
	private:
		std::vector<Vecf> _value;

	public:
		explicit Matf(int rows, int cols);
		Matf(std::vector<Vecf> value);

		int size() const;

		int rows() const;
		int cols() const;

		Vecf &operator[](int index);

		Matf &operator+=(Matf &mat);
		Matf &operator-=(Matf &mat);
		Matf &operator*=(Matf &mat);
		Matf &operator*=(float const scalar);
	};

	Matf operator+(Matf &mat1, Matf &mat2);
	Matf operator-(Matf &mat1, Matf &mat2);
	Matf operator*(Matf &mat1, Matf &mat2);
	Matf operator*(int const scalar, Matf const &mat);

	bool operator==(Matf &mat1, Matf &mat2);
	bool operator!=(Matf &mat1, Matf &mat2);

	std::ostream& operator<<(std::ostream& stream, Matf &mat);
}

#endif
