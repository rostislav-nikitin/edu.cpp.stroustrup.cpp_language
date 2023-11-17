#ifndef ICOLORSHAPE_HPP
#define ICOLORSHAPE_HPP

#include "color.hpp"
#include "ishape.hpp"

namespace UI
{
	namespace Abstractions
	{
		class ILine;
		class ITriangle;
		class IRectangle;
		class ICircle;
	}
}

namespace UI
{
	namespace Abstractions
	{
		class IColorShape : public IShape
		{
		protected:
			Color _color;
		public:
			IColorShape(Color color = Color(1.f, 1.f, 1.f, 1.f));

			virtual Color get_color() const;
			virtual void set_color(Color const color);

			virtual bool intersects(IColorShape const *shape) const = 0;
			virtual bool intersects(ILine const *line) const = 0;
			virtual bool intersects(ITriangle const *triangle) const = 0;
			virtual bool intersects(IRectangle const *rectangle) const = 0;
			virtual bool intersects(ICircle const *circle) const = 0;
		};
	}
}

#endif
