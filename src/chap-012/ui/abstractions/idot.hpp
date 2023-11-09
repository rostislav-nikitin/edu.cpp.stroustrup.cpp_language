#ifndef IDOT_HPP
#define IDOT_HPP

#include "icolorshape.hpp"
#include "color.hpp"
#include "point.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IDot : public IColorShape
		{
		protected:
			Point _position;
		public:
			IDot(Color color = Color(1.f, 1.f, 1.f, 1.f), Point position = Point(0.f, 0.f));

			virtual Point get_position() const;
			virtual void set_position(Point const position);
		};
	}
}

#endif
