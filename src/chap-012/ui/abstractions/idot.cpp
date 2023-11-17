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

		bool IDot::intersects(IColorShape const *shape) const
		{
			throw std::runtime_error("Not Implemented");
		}

		bool IDot::intersects(ILine const *line) const
		{
			throw std::runtime_error("Not Implemented");
		}

		bool IDot::intersects(ITriangle const *triangle) const
		{
			throw std::runtime_error("Not Implemented");
		}

		bool IDot::intersects(IRectangle const *rectangle) const
		{
			throw std::runtime_error("Not Implemented");
		}

		bool IDot::intersects(ICircle const *circle) const
		{
			throw std::runtime_error("Not Implemented");
		}
	}
}
