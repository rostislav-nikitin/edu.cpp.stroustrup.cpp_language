#ifndef IXYCOORDINATES_HPP
#define IXYCOORDINATES_HPP

#include "color.hpp"
#include "point.hpp"
#include "compositeshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IXYCoordinates : public CompositeShape
		{
		protected:
			Color _color;
			Point _position;
			float _line_width;

		public:
			IXYCoordinates(Color color, Point position, float line_width);
		};
	}
}

#endif
