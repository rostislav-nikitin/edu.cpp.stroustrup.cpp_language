#ifndef IRECTANGLE_HPP
#define IRECTANGLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IRectangle;
	}
}

#include "iline.hpp"
#include "itriangle.hpp"
#include "icircle.hpp"

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

			bool intersects(IColorShape const *shape) const override;
			bool intersects(ILine const *line) const;
			bool intersects(ITriangle const *triangle) const;
			bool intersects(IRectangle const *rectangle) const;
			bool intersects(ICircle const *circle) const;
		};
	}
}

#endif
