#include "collisiondetector.hpp"

namespace UI
{
	namespace Engine
	{
		// Visitor pattern
		//private:
		bool CollisionDetector::_detect(ILine const *line_lhs, ILine const *line_rhs) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
		bool CollisionDetector::_detect(ITriangle const *triangle_lhs, ITriangle const *triangle_rhs) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
		bool CollisionDetector::_detect(IRectangle const *rectangle_lhs, IRectangle const *rectangle_rhs) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
		bool CollisionDetector::_detect(ICircle const *circle_lhs, ICircle const *circle_rhs) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool CollisionDetector::_detect(ILine const *line, ITriangle const *triangle) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
		bool CollisionDetector::_detect(ILine const *line, IRectangle const *rectangle) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
		bool CollisionDetector::_detect(ILine const *line, ICircle const *circle) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool CollisionDetector::_detect(ITriangle const *triangle_lhs, IRectangle const *triangle_rhs) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}
		bool CollisionDetector::_detect(ITriangle const *triangle, ICircle const *circle) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		bool CollisionDetector::_detect(IRectangle const *rectangle, ICircle const *circle) const
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			return true;
		}

		//public:
		bool CollisionDetector::detect(ILine const *line_lhs, ILine const *line_rhs) const
		{
			return _detect(line_lhs, line_rhs);
		}
		bool CollisionDetector::detect(ILine const *line, ITriangle const *triangle) const
		{
			return _detect(line, triangle);
		}
		bool CollisionDetector::detect(ILine const *line, IRectangle const *rectangle) const
		{
			return _detect(line, rectangle);
		}
		bool CollisionDetector::detect(ILine const *line, ICircle const *circle) const
		{
			return _detect(line, circle);
		}

		bool CollisionDetector::detect(ITriangle const *triangle, ILine const *line) const
		{
			return _detect(line, triangle);
		}
		bool CollisionDetector::detect(ITriangle const *triangle_lhs, ITriangle const *triangle_rhs) const
		{
			return _detect(triangle_lhs, triangle_rhs);
		}
		bool CollisionDetector::detect(ITriangle const *triangle, IRectangle const *rectangle) const
		{
			return _detect(triangle, rectangle);
		}
		bool CollisionDetector::detect(ITriangle const *triangle, ICircle const *circle) const
		{
			return _detect(triangle, circle);
		}

		bool CollisionDetector::detect(IRectangle const *rectangle, ILine const *line) const
		{
			return _detect(line, rectangle);
		}
		bool CollisionDetector::detect(IRectangle const *rectangle, ITriangle const *triangle) const
		{
			return _detect(triangle, rectangle);
		}
		bool CollisionDetector::detect(IRectangle const *rectangle_lhs, IRectangle const *rectangle_rhs) const
		{
			return _detect(rectangle_lhs, rectangle_rhs);
		}
		bool CollisionDetector::detect(IRectangle const *rectangle, ICircle const *circle) const
		{
			return _detect(rectangle, circle);
		}

		bool CollisionDetector::detect(ICircle const *circle, ILine const *line) const
		{
			return _detect(line, circle);
		}
		bool CollisionDetector::detect(ICircle const *circle, ITriangle const *triangle) const
		{
			return _detect(triangle, circle);
		}
		bool CollisionDetector::detect(ICircle const *circle, IRectangle const *rectangle) const
		{
			return _detect(rectangle, circle);
		}
		bool CollisionDetector::detect(ICircle const *circle_lhs, ICircle const *circle_rhs) const
		{
			return _detect(circle_lhs, circle_rhs);
		}

		bool collision_detect(IShape const *shape_lhs, IShape const *shape_rhs)
		{
			CollisionDetector cd;

			if(dynamic_cast<ILine const *>(shape_lhs))
			{
				if(dynamic_cast<ILine const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ILine const *>(shape_lhs), dynamic_cast<ILine const *>(shape_rhs));
				}
				if(dynamic_cast<ITriangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ILine const *>(shape_lhs), dynamic_cast<ITriangle const *>(shape_rhs));
				}
				if(dynamic_cast<IRectangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ILine const *>(shape_lhs), dynamic_cast<IRectangle const *>(shape_rhs));
				}
				if(dynamic_cast<ICircle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ILine const *>(shape_lhs), dynamic_cast<ICircle const *>(shape_rhs));
				}
			}
			else if(dynamic_cast<ITriangle const *>(shape_lhs))
			{
				if(dynamic_cast<ILine const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ITriangle const *>(shape_lhs), dynamic_cast<ILine const *>(shape_rhs));
				}
				if(dynamic_cast<ITriangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ITriangle const *>(shape_lhs), dynamic_cast<ITriangle const *>(shape_rhs));
				}
				if(dynamic_cast<IRectangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ITriangle const *>(shape_lhs), dynamic_cast<IRectangle const *>(shape_rhs));
				}
				if(dynamic_cast<ICircle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ITriangle const *>(shape_lhs), dynamic_cast<ICircle const *>(shape_rhs));
				}
			}
			else if(dynamic_cast<IRectangle const *>(shape_lhs))
			{
				if(dynamic_cast<ILine const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<IRectangle const *>(shape_lhs), dynamic_cast<ILine const *>(shape_rhs));
				}
				if(dynamic_cast<ITriangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<IRectangle const *>(shape_lhs), dynamic_cast<ITriangle const *>(shape_rhs));
				}
				if(dynamic_cast<IRectangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<IRectangle const *>(shape_lhs), dynamic_cast<IRectangle const *>(shape_rhs));
				}
				if(dynamic_cast<ICircle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<IRectangle const *>(shape_lhs), dynamic_cast<ICircle const *>(shape_rhs));
				}
			}
			if(dynamic_cast<ICircle const *>(shape_lhs))
			{
				if(dynamic_cast<ILine const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ICircle const *>(shape_lhs), dynamic_cast<ILine const *>(shape_rhs));
				}
				if(dynamic_cast<ITriangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ICircle const *>(shape_lhs), dynamic_cast<ITriangle const *>(shape_rhs));
				}
				if(dynamic_cast<IRectangle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ICircle const *>(shape_lhs), dynamic_cast<IRectangle const *>(shape_rhs));
				}
				if(dynamic_cast<ICircle const *>(shape_rhs))
				{
					return cd.detect(dynamic_cast<ICircle const *>(shape_lhs), dynamic_cast<ICircle const *>(shape_rhs));
				}
			}

			throw std::runtime_error("Specified shape collision detection not supported.");
		}
	}
}
