#ifndef ICOLORSHAPE_HPP
#define ICOLORSHAPE_HPP

#include "color.hpp"
#include "ishape.hpp"

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
		};
	}
}

#endif
