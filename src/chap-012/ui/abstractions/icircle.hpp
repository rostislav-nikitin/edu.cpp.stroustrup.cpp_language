#ifndef ICIRCLE_HPP
#define ICIRCLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ICircle;
	}
}

#include "iline.hpp"
#include "itriangle.hpp"
#include "irectangle.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ICircle : public IColorShape
		{
		protected:
			Point _center;
			float _radius;
		public:
			ICircle(Color color, Point center, float radius);

			bool intersects(IColorShape const *shape) const override;
			bool intersects(ILine const *line) const;
			bool intersects(ITriangle const *triangle) const;
			bool intersects(IRectangle const *rectangle) const;
			bool intersects(ICircle const *circle) const;
		};
	}
}

#endif
