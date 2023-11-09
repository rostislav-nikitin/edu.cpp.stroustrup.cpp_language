#include "icolorshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		IColorShape::IColorShape(Color color) : _color(color)
		{
		}

		Color IColorShape::get_color() const
		{
			return _color;
		}

		void IColorShape::set_color(Color const color)
		{
			_color = color;
		}
	}
}
