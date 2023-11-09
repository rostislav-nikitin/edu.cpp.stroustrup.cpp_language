#include "idot.hpp"

namespace UI
{
	namespace Abstractions
	{
		IDot::IDot(Color color, Point position) : IColorShape(color),  _position(position)
		{
		}

		Point IDot::get_position() const
		{
			return _position;
		}

		void IDot::set_position(Point const position)
		{
			_position = position;
		}
	}
}
