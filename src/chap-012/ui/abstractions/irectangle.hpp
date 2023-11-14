#ifndef IRECTANGLE_HPP
#define IRECTANGLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IRectangle : public IColorShape
		{
		protected:
			Point _position;
			float _width;
			float _height;

		public:
			IRectangle(Color color, Point position, float width, float height);

		};
	}
}

#endif
